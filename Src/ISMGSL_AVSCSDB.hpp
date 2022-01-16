#include <map>

#ifndef MXPSQL_ISMGSL_AVSCSDB_HPP
#define MXPSQL_ISMGSL_AVSCSDB_HPP

namespace MXPSQL::ISMGSL_AVSCSDB{
    // forward declaration
    class GSLCursor;   

    // polymorphism here
    class IDocument{
        public:
            virtual ~IDocument(){}
    };

    // enums
    // enum for the document items
    enum class DocumentItemType{
        Unknown,
        Text,
        Number,
        Null,
        Boolean,
        DocumentPointer,
        ItemPointer,
        File,
        Binary
    };

    // enum for the documents
    enum class DocumentType{
        KeyValue,
        WideColumn,
        Document,
        Relational
    };

    // document item
    class DocumentItem{
        
    };

    // database document
    // key value document
    class KeyValueDocument : public IDocument{
        std::map<std::string, DocumentItem> kvp;
    };

    // wide column database
    class WideColumnDocument : public IDocument{
        std::map<std::string, std::map<std::string, DocumentItem> > wideColumns;
    };

    // database handle
    class ISMGSL_AVSCSDB{
        private:
        struct DATABASE{
            // database stuff
            int i = 0;
            std::map<std::string, IDocument> databases;
        };

        public:
        // constructor
        ISMGSL_AVSCSDB();

        // database
        DATABASE gsldb;

        // status check
        int statusRc = 0;

        void throwOnError();

        // database open
        bool open();

        // cursor
        GSLCursor* cursor();
        
    };

    // you do the operations here for the documents
    class GSLCursor{
        private:
        class LangExec{
            public:
            // language based operation
            ISMGSL_AVSCSDB database;
        };

        class FQS{
            public:
            // function based operation
            ISMGSL_AVSCSDB database;
        };

        public:
        // database
        ISMGSL_AVSCSDB database;

        // operations
        FQS function_operation;
        LangExec language_operation;

        GSLCursor(ISMGSL_AVSCSDB database){
            this->database = database;
        }


    };

    class GSLCursor;

    // ismgsl_avscsdb impl
    ISMGSL_AVSCSDB::ISGML_AVSCSDB(){
    }

    bool ISMGSL_AVSCSDB::open(){
        // open the database

        bool status = true;

            try{

            }
            catch(...){
                statusRc = -1;
                status = false;
            }

            return status;
    }

    void ISMGSL_AVSCSDB::throwOnError(){
        // throw an error if statusRc is not 0

        switch(statusRc){
            default:
                break;
        }
    }

    GSLCursor* ISMGSL_AVSCSDB::cursor(){
        // get cursor

        GSLCursor* cursor = new GSLCursor(this);

        return cursor;
    }

    // gslcursor impl

}



#endif