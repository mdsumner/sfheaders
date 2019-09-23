#ifndef R_SFHEADERS_POLYGON_CLOSE_POLYGON_H
#define R_SFHEADERS_POLYGON_CLOSE_POLYGON_H

#include <Rcpp.h>

namespace sfheaders {
namespace polygon_utils {

  inline void check_closed_rows( int n_row ) {
    if( n_row < 4 ) {
      Rcpp::stop("sfheaders - closed polygons must have at least 4 rows");
    }
  }

  // TODO
  // close polygons (matrices, lists, data.frames)
  // check if closed for 2-columns, 3-columns & 4-columns
  // closed when first row == last row
  inline Rcpp::IntegerMatrix close_polygon(
    Rcpp::IntegerMatrix& im,
    bool close = true
  ) {

    if( !close ) {
      return im;
    }

    R_xlen_t n_row = im.nrow();
    R_xlen_t n_col = im.ncol();
    R_xlen_t i;

    bool is_closed = true;

    Rcpp::IntegerVector first_row = im( 0, Rcpp::_ );
    Rcpp::IntegerVector last_row = im( n_row - 1, Rcpp::_ );

    for( i = 0; i < n_col; i++ ) {
      if( first_row[i] != last_row[i] ) {
        is_closed = false;
        break;
      }
    }

    if( !is_closed ) {
      Rcpp::IntegerMatrix im2( n_row + 1, n_col );
      for( i = 0; i < n_col; i++ ) {
        Rcpp::IntegerVector iv( n_row + 1);
        Rcpp::Range rng( 0, n_row - 1 );

        iv[ rng ] = im( Rcpp::_, i );
        iv[ n_row ] = first_row[i];
        im2( Rcpp::_ , i ) = iv;
      }
      check_closed_rows( im2.nrow() );
      return im2;
    }

    // it is closed
    check_closed_rows( im.nrow() );
    return im;
  }

  inline Rcpp::NumericMatrix close_polygon(
      Rcpp::NumericMatrix& nm,
      bool close = true
  ) {

    if( !close ) {
      return nm;
    }

    R_xlen_t n_row = nm.nrow();
    R_xlen_t n_col = nm.ncol();
    R_xlen_t i;

    bool is_closed = true;

    Rcpp::NumericVector first_row = nm( 0, Rcpp::_ );
    Rcpp::NumericVector last_row = nm( n_row - 1, Rcpp::_ );

    for( i = 0; i < n_col; i++ ) {
      if( first_row[i] != last_row[i] ) {
        is_closed = false;
        break;
      }
    }

    if( !is_closed ) {
      Rcpp::NumericMatrix nm2( n_row + 1, n_col );
      for( i = 0; i < n_col; i++ ) {
        Rcpp::NumericVector nv( n_row + 1);
        Rcpp::Range rng( 0, n_row - 1 );

        nv[ rng ] = nm( Rcpp::_, i );
        nv[ n_row ] = first_row[i];
        nm2( Rcpp::_ , i ) = nv;
      }
      check_closed_rows( nm2.nrow() );
      return nm2;
    }

    // it is closed
    check_closed_rows( nm.nrow() );
    return nm;
  }

} // polygon
} // sfheaders

#endif
