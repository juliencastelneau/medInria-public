#include <medAbstractDataSource.h>

// /////////////////////////////////////////////////////////////////
// medAbstractDataSourcePrivate
// /////////////////////////////////////////////////////////////////

class medAbstractDataSourcePrivate
{
public:
};

// /////////////////////////////////////////////////////////////////
// medAbstractDataSource
// /////////////////////////////////////////////////////////////////

medAbstractDataSource::medAbstractDataSource(void) : dtkAbstractObject(), d(new medAbstractDataSourcePrivate)
{
	
}

medAbstractDataSource::~medAbstractDataSource(void)
{
	
}
