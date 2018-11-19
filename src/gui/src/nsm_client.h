/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef NSM_CLIENT_H
#define NSM_CLIENT_H

#ifdef H2CORE_HAVE_OSC

#include <hydrogen/object.h>
#include <cassert>


/**
* @class NsmClient
*
* @brief Non session manager client implementation
*
*
* @author Sebastian Moors
*
*/

typedef void * nsm_client_t;

class NsmClient : public H2Core::Object
{
	H2_OBJECT
	public:

		static NsmClient* __instance;
		~NsmClient();

		pthread_t m_NsmThread;

		static void create_instance();
		static NsmClient* get_instance() { assert(__instance); return __instance; }

		void createInitialClient();
        void setReadyForOpen();
        
        void sendDirtyState(bool state);
        void isDirty();
        void isClean();
        void optionalGuiShown();
        void optionalGuiHidden();
        bool isActive();

		void shutdown();

	private:
		NsmClient();
        bool ready_for_open;
        nsm_client_t* nsm;
        bool is_dirty;
        bool is_active;

};

#endif /* H2CORE_HAVE_OSC */

#endif // NSM_CLIENT_H
