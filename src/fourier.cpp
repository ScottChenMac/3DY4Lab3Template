/*
Comp Eng 3DY4 (Computer Systems Integration Project)

Department of Electrical and Computer Engineering
McMaster University
Ontario, Canada
*/

// source code for Fourier-family of functions
#include "dy4.h"
#include "fourier.h"

// just DFT function (no FFT yet)
void DFT(const std::vector<float> &x, std::vector<std::complex<float>> &Xf) {
	Xf.clear(); Xf.resize(x.size(), static_cast<std::complex<float>>(0));
	for (int m = 0; m < (int)Xf.size(); m++) {
		for (int k = 0; k < (int)x.size(); k++) {
				std::complex<float> expval(0, -2*PI*(k*m) / x.size());
				Xf[m] += x[k] * std::exp(expval);
		}
	}
}

// function to compute the magnitude values in a complex vector
void computeVectorMagnitude(const std::vector<std::complex<float>> &Xf, std::vector<float> &Xmag)
{
	// only the positive frequencies
	Xmag.clear(); Xmag.resize(Xf.size(), static_cast<float>(0));
	for (int i = 0; i < (int)Xf.size(); i++) {
		Xmag[i] = std::abs(Xf[i])/Xf.size();
	}
}

// add your own code to estimate the PSD
