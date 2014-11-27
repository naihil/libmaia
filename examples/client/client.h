#ifndef CLIENT_H
#define CLIENT_H

// CORE includes
#include <QList>
#include <QObject>
#include <QVariant>

// NETWORK includes
#include <QSslError>

// fwd
class QNetworkReply;
class MaiaXmlRpcClient;

class Client : public QObject {
	Q_OBJECT
	
	public:
		Client(QObject* parent = 0);
		
	public slots:
		void doClient();
	
	private slots:
		void testResponse(QVariant &);
		void testFault(int, const QString &);
		void towelResponse(QVariant &);
		void handleSslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
	
	private:
		MaiaXmlRpcClient *rpc;
};

#endif
