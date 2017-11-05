//
// IndexDBRef.h
//
// IndexDBRef: Reference to an indexed document. Keeps track of all
//              information stored on the document, either by the dig 
//              or temporary search information.
//
// Part of the ht://Dig package   <http://www.htdig.org/>
// Copyright (c) 1995-2004 The ht://Dig Group
// For copyright details, see the file COPYING in your distribution
// or the GNU Library General Public License (LGPL) version 2 or later
// <http://www.gnu.org/copyleft/lgpl.html>
//
// $Id: IndexDBRef.h,v 1.1.2.2 2007/04/26 16:26:15 aarnone Exp $
//

#ifndef _IndexDBRef_h_
#define _IndexDBRef_h_

#include "htString.h"
#include "List.h"

#include <time.h>


class IndexDBRef : public Object
{
    public:
    //
    // Construction/Destruction
    //
    IndexDBRef();
    ~IndexDBRef();


    //
    // Get functions
    //
    String          DocURL()                {return URL;}
    String          DocName()               {return doc_name;}
    String          DocID()                 {return id;} 
    time_t          DocTime()               {return time;}
    time_t          DocAltTime()            {return alt_time;}
    time_t          DocExpired()            {return expired;}
    int             DocSig()                {return sig;} 
    int             DocHopCount()           {return hopCount;}
    int             DocBacklinks()          {return backlinks;}
    int             DocSpiderable()         {return spiderable;}
    int             DocSize()               {return docSize;}
//    List            *Descriptions()         {return &descriptions;}

    //
    // Set functions
    // 
    void        DocURL(const char *u)       {URL = u;}
    void        DocName(const char *u)      {doc_name = u;}
    void        DocID(const char *u)        {id = u;}
    void        DocTime(time_t t)           {time = t;}
    void        DocAltTime(time_t t)        {alt_time = t;}
    void        DocExpired(time_t e)        {expired = e;}
    void        DocSig(int i)               {sig = i;}
    void        DocHopCount(int i)          {hopCount = i;}
    void        DocBacklinks(int i)         {backlinks = i;} 
    void        DocSpiderable(int i)        {spiderable = i;}
    void        DocSize(int i)              {docSize = i;}
//    void        Descriptions(List &l)       {descriptions = l;}

//    void        AddDescription(const char *d, HtWordList &words);
 

    //
    // An IndexDBRef can read itself from a character string
    // and convert itself into a character string
    //
    void        Serialize(String &s);
    void        Deserialize(String &s);

    //
    // Reset Everything
    // 
    void        Clear();



    protected:

    // 
    // This is the URL of the document (the key for BDB).
    //
    String      URL;


    //
    // The rest of these variables will be stored when serializing
    //

    // for normal spider runs, this is just a copy of the URL. however, for
    // documents added through add_single, this will be the name of the doc_name
    // parameter passed in to the function (which may or may not be spiderable).
    // So, for instance, if you want to add a text document that is in memory, URL
    // will be something like 'TXTDOC05' and doc_name will be 'myfile.txt'
    String      doc_name;

    // This is the id for the document. This is available as an alternate
    // identification method to URL (although the index is still URL based)
    String      id;

    // This is the time specified in the document's header
    // Usually that's the last modified time, for servers that return it.
    // Sometimes this will be overridden by meta information in the 
    // document head.
    time_t      time;

    // An alternate time that can be used to do time checking. Used mostly
    // in the Spider's addSingleDoc.
    time_t      alt_time;

    // This is when the document is marked as expiring, as retruned by the
    // web server. Like the time value, can also be overriden by a meta
    // tag in the document head.
    time_t      expired;

    // This is a signature of the document. (e.g. md5sum, checksum...)
    // This is currently unused.
    long int    sig;

    // This is a count of the number of hops from start_urls to here.
    int         hopCount;

    // This is a count of the links to the document (incoming links).
    int         backlinks;

    // this is the size of the document
    int         docSize;

    // this denotes if the document is considered spiderable: 
    // AKA it is not not retrievable (certain custom documents
    // might not be spiderable - see doc_name)
    int         spiderable;

    // This is a list of Strings, the text of links pointing to this document.
    // (e.g. <a href="docURL">description</a>
    //List        descriptions;

};

#endif


