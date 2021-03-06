% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/sfc.R
\name{sfc_point}
\alias{sfc_point}
\title{sfc POINT}
\usage{
sfc_point(obj, x = NULL, y = NULL, z = NULL, m = NULL)
}
\arguments{
\item{obj}{sorted vector, matrix or data.frame}

\item{x}{x geometry column}

\item{y}{y geometry column}

\item{z}{z geometry column}

\item{m}{m geometry column}
}
\value{
\code{sfc} object of POINT geometries
}
\description{
constructs sfc of POINT objects
}
\section{notes}{

sfheaders functions do not perform any validity checks on the geometries.
Nor do they set Coordinate Reference Systems, EPSG, PROJ4 or precision attributes.

The data.frame and matrices you send into the sfheader functions must be ordered.
}

\examples{

x <- c(1:3)
sfc_point( x )

x <- matrix( c(1:10) , ncol = 2 )
sfc_point( x )

x <- setNames( as.data.frame( x ), c("x","y") )
sfc_point( x )
sfc_point( obj = x, x = "x", y = "y" )
sfc_point( obj = x, x = "y", y = "x" )

}
