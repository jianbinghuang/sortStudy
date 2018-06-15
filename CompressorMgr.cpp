
#ifndef CompressorMgr_H
#define CompressorMgr_H

class CompressorMgr
{

  public:

    CompressorMgr();
    CompressorMgr( const CompressorMgr &orig );
    virtual ~CompressorMgr();
    CompressorMgr &operator=( const CompressorMgr &rhs );

    virtual JtBool reset();

    // Wholesale buffer compression/decompression interfaces
    virtual JtBool compress( const unsigned char  *inBuffer, 
                             int                  inLength,
                             unsigned char        *outBuffer,
                             int                  maxOutLength,
                             int                  &outLength ) = 0;

    virtual JtBool uncompress( const JtUChar *inBuffer, 
                               JtSize        inLength,
                               JtUChar       *outBuffer,
                               JtSize        maxOutLength,
                               JtSize       &outLength ) = 0;

    // Stream decompression interface
    virtual JtBool beginUncompress() = 0;
    virtual JtBool doUncompress (const JtUChar *&pNextIn,
                                 JtSize         &cAvailIn,
                                 JtUChar       *&pNextOut,
                                 JtSize         &cAvailOut) = 0;
    virtual JtBool endUncompress() = 0;

    // Stream compression interface
    virtual JtBool beginCompress() = 0;
    virtual JtBool doCompress (const JtUChar *&pNextIn,
                               JtSize         &cAvailIn,
                               JtUChar       *&pNextOut,
                               JtSize         &cAvailOut) = 0;
    virtual JtBool endCompress() = 0;
};

#endif
