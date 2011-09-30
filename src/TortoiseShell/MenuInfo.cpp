// TortoiseGit - a Windows shell extension for easy version control

// Copyright (C) 2003-2008 - TortoiseGit

// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
#include "stdafx.h"
#include "menuinfo.h"
#include "resource.h"
#include "Globals.h"

MenuInfo menuInfo[] =
{
	{ ShellMenuClone,						MENUCLONE,			IDI_CLONE,				IDS_MENUCLONE,			IDS_MENUDESCCLONE,
	ITEMIS_FOLDER, ITEMIS_INSVN|ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuPull,						MENUPULL,			IDI_PULL,				IDS_MENUPULL,			IDS_MENUDESCPULL,
	ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuFetch,						MENUFETCH,			IDI_PULL,				IDS_MENUFETCH,			IDS_MENUDESCFETCH,
	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	{ ShellMenuPush,						MENUPUSH,			IDI_PUSH,				IDS_MENUPUSH,			IDS_MENUDESCPUSH,
	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	{ ShellMenuSync,						MENUSYNC,			IDI_RELOCATE,				IDS_MENUSYNC,			IDS_MENUDESCSYNC,
	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },


//	{ ShellMenuCheckout,					MENUCHECKOUT,		IDI_CHECKOUT,			IDS_MENUCHECKOUT,			IDS_MENUDESCCHECKOUT,
//	ITEMIS_FOLDER, ITEMIS_INSVN|ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0 },

//	{ ShellMenuUpdate,					MENUSUBUPDATE,			IDI_UPDATE,				IDS_MENUUPDATE,				IDS_MENUDESCUPDATE,
//	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

	{ ShellMenuCommit,						MENUCOMMIT,			IDI_COMMIT,				IDS_MENUCOMMIT,				IDS_MENUDESCCOMMIT,
	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	{ ShellMenuGitSVNDCommit,				MENUSVNDCOMMIT,			IDI_COMMIT,			IDS_MENUSVNDCOMMIT,			IDS_MENUSVNDCOMMIT_DESC,
	ITEMIS_INSVN|ITEMIS_GITSVN, 0, ITEMIS_FOLDERINSVN|ITEMIS_GITSVN, 0, 0, 0, 0, 0 },

	{ ShellMenuGitSVNRebase,				MENUSVNREBASE,		IDI_REBASE,				IDS_MENUSVNREBASE,				IDS_MENUSVNREBASE_DESC,
	ITEMIS_INSVN|ITEMIS_GITSVN, 0, ITEMIS_FOLDERINSVN|ITEMIS_GITSVN, 0, 0, 0, 0, 0},

	{ ShellMenuGitSVNIgnore,				MENUSVNIGNORE,		IDI_IGNORE,				IDS_MENUSVNIGNORE,				IDS_MENUSVNIGNORE_DESC,
	ITEMIS_INSVN|ITEMIS_GITSVN, 0, ITEMIS_FOLDERINSVN|ITEMIS_GITSVN, 0, 0, 0, 0, 0},

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

	{ ShellMenuDiff,						MENUDIFF,			IDI_DIFF,				IDS_MENUDIFF,				IDS_MENUDESCDIFF,
	ITEMIS_INSVN|ITEMIS_ONLYONE, 0, ITEMIS_TWO, 0, 0, 0, 0, 0 },

	{ ShellMenuPrevDiff,					MENUPREVDIFF,			IDI_DIFF,			IDS_MENUPREVDIFF,			IDS_MENUDESCPREVDIFF,
	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, 0, 0, 0, 0, 0, 0 },

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},
//	{ ShellMenuUrlDiff,						MENUURLDIFF,		IDI_DIFF,				IDS_MENUURLDIFF,			IDS_MENUDESCURLDIFF,
//	ITEMIS_INSVN|ITEMIS_ONLYONE|ITEMIS_EXTENDED, 0, ITEMIS_FOLDERINSVN|ITEMIS_EXTENDED|ITEMIS_ONLYONE, 0, 0, 0, 0, 0 },

	{ ShellMenuLog,							MENULOG,			IDI_LOG,				IDS_MENULOG,				IDS_MENUDESCLOG,
	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, 0, 0 },

	{ ShellMenuRefLog,						MENUREFLOG,			IDI_LOG,				IDS_MENUREFLOG,				IDS_MENUDESCREFLOG,
	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, 0, 0 },

	{ ShellMenuRefBrowse,					MENUREFBROWSE,		IDI_REPOBROWSE,			IDS_MENUREFBROWSE,			IDS_MENUDESCREFBROWSE,
	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, 0, 0 },


//	{ ShellMenuRepoBrowse,					MENUREPOBROWSE,		IDI_REPOBROWSE,			IDS_MENUREPOBROWSE,			IDS_MENUDESCREPOBROWSE,
//	ITEMIS_ONLYONE, 0, ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, 0, 0, 0, 0 },

	{ ShellMenuShowChanged,					MENUSHOWCHANGED,	IDI_SHOWCHANGED,		IDS_MENUSHOWCHANGED,		IDS_MENUDESCSHOWCHANGED,
	ITEMIS_INSVN, 0, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0},

	{ ShellMenuRebase,					    MENUREBASE,			IDI_REBASE,				IDS_MENUREBASE,				IDS_MENUREBASE,
	ITEMIS_INSVN, 0, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0},

//	{ ShellMenuRevisionGraph,				MENUREVISIONGRAPH,	IDI_REVISIONGRAPH,		IDS_MENUREVISIONGRAPH,		IDS_MENUDESCREVISIONGRAPH,
//	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, 0, 0, 0, 0},

	{ ShellMenuStashSave,				    MENUSTASHSAVE,		IDI_COMMIT,				IDS_MENUSTASHSAVE,				IDS_MENUSTASHSAVE,
	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },
	{ ShellMenuStashApply,				    MENUSTASHAPPLY,	    IDI_RELOCATE,			IDS_MENUSTASHAPPLY,				IDS_MENUSTASHAPPLY,
	ITEMIS_INSVN|ITEMIS_STASH, 0, ITEMIS_FOLDERINSVN|ITEMIS_STASH, 0, 0, 0, 0, 0 },
	{ ShellMenuStashPop,				    MENUSTASHPOP,	    IDI_RELOCATE,			IDS_MENUSTASHPOP,				IDS_MENUSTASHPOP,
	ITEMIS_INSVN|ITEMIS_STASH, 0, ITEMIS_FOLDERINSVN|ITEMIS_STASH, 0, 0, 0, 0, 0 },
	{ ShellMenuStashList,				    MENUSTASHAPPLY,	    IDI_LOG,				IDS_MENUSTASHLIST,				IDS_MENUSTASHLIST,
	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },


	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

	{ ShellMenuConflictEditor,				MENUCONFLICTEDITOR,	IDI_CONFLICT,			IDS_MENUCONFLICT,			IDS_MENUDESCCONFLICT,
	ITEMIS_INSVN|ITEMIS_CONFLICTED, ITEMIS_FOLDER, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuResolve,						MENURESOLVE,		IDI_RESOLVE,			IDS_MENURESOLVE,			IDS_MENUDESCRESOLVE,
	ITEMIS_INSVN|ITEMIS_CONFLICTED, 0, ITEMIS_INSVN|ITEMIS_FOLDER, 0, ITEMIS_FOLDERINSVN, 0, 0, 0 },


	{ ShellMenuRename,						MENURENAME,			IDI_RENAME,				IDS_MENURENAME,				IDS_MENUDESCRENAME,
	ITEMIS_INSVN|ITEMIS_ONLYONE|ITEMIS_INVERSIONEDFOLDER, ITEMIS_WCROOT, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuRemove,						MENUREMOVE,			IDI_DELETE,				IDS_MENUREMOVE,				IDS_MENUDESCREMOVE,
	ITEMIS_INSVN|ITEMIS_INVERSIONEDFOLDER, ITEMIS_ADDED|ITEMIS_WCROOT, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuRemoveKeep,					MENUREMOVEKEEP,			IDI_DELETE,				IDS_MENUREMOVEKEEP,			IDS_MENUDESCREMOVEKEEP,
	ITEMIS_INSVN|ITEMIS_INVERSIONEDFOLDER, ITEMIS_ADDED|ITEMIS_WCROOT, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuRevert,						MENUREVERT,			IDI_REVERT,				IDS_MENUREVERT,				IDS_MENUDESCREVERT,
	ITEMIS_INSVN, ITEMIS_NORMAL|ITEMIS_ADDED, ITEMIS_FOLDERINSVN, ITEMIS_ADDED, 0, 0, 0, 0 },

	{ ShellMenuRevert,						MENUREVERT,			IDI_REVERT,				IDS_MENUUNDOADD,			IDS_MENUDESCUNDOADD,
	ITEMIS_ADDED, ITEMIS_NORMAL, ITEMIS_FOLDERINSVN|ITEMIS_ADDED, 0, 0, 0, 0, 0 },

//	{ ShellMenuDelUnversioned,				MENUDELUNVERSIONED,	IDI_DELUNVERSIONED,		IDS_MENUDELUNVERSIONED,		IDS_MENUDESCDELUNVERSIONED,
//	ITEMIS_FOLDER|ITEMIS_INSVN, 0, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	{ ShellMenuCleanup,						MENUCLEANUP,		IDI_CLEANUP,			IDS_MENUCLEANUP,			IDS_MENUDESCCLEANUP,
	ITEMIS_INSVN|ITEMIS_FOLDER, 0, ITEMIS_FOLDERINSVN|ITEMIS_FOLDER, 0, 0, 0, 0, 0 },

//	{ ShellMenuLock,						MENULOCK,			IDI_LOCK,				IDS_MENU_LOCK,				IDS_MENUDESC_LOCK,
//	ITEMIS_INSVN, ITEMIS_LOCKED|ITEMIS_ADDED, ITEMIS_FOLDERINSVN, ITEMIS_LOCKED|ITEMIS_ADDED, 0, 0, 0, 0 },

//	{ ShellMenuUnlock,						MENUUNLOCK,			IDI_UNLOCK,				IDS_MENU_UNLOCK,			IDS_MENUDESC_UNLOCK,
//	ITEMIS_INSVN|ITEMIS_LOCKED, 0, ITEMIS_FOLDER|ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0 },

//	{ ShellMenuUnlockForce,					MENUUNLOCK,			IDI_UNLOCK,				IDS_MENU_UNLOCKFORCE,		IDS_MENUDESC_UNLOCKFORCE,
//	ITEMIS_INSVN|ITEMIS_LOCKED, 0, ITEMIS_FOLDER|ITEMIS_INSVN|ITEMIS_EXTENDED, 0, 0, 0, 0, 0 },

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

//	{ ShellMenuCopy,						MENUCOPY,			IDI_COPY,				IDS_MENUBRANCH,				IDS_MENUDESCCOPY,
//	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_ADDED, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, 0, 0, 0, 0 },

	{ ShellMenuSwitch,						MENUSWITCH,			IDI_SWITCH,				IDS_MENUSWITCH,				IDS_MENUDESCSWITCH,
	ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuMerge,						MENUMERGE,			IDI_MERGE,				IDS_MENUMERGE,				IDS_MENUDESCMERGE,
	ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, 0, 0, 0, 0, 0, 0 },
//	{ ShellMenuMergeAll,					MENUMERGEALL,		IDI_MERGE,				IDS_MENUMERGEALL,			IDS_MENUDESCMERGEALL,
//	ITEMIS_INSVN|ITEMIS_ONLYONE|ITEMIS_EXTENDED, ITEMIS_ADDED, ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE|ITEMIS_EXTENDED, 0, 0, 0, 0, 0 },

	{ ShellMenuBranch,						MENUCOPY,			IDI_COPY,				IDS_MENUBRANCH,				IDS_MENUDESCCOPY,
	ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0, 0 },
	{ ShellMenuTag,							MENUTAG,			IDI_TAG,				IDS_MENUTAG,				IDS_MENUDESCCOPY,
	ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuExport,						MENUEXPORT,			IDI_EXPORT,				IDS_MENUEXPORT,				IDS_MENUDESCEXPORT,
	ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0, 0 },

//	{ ShellMenuRelocate,					MENURELOCATE,		IDI_RELOCATE,			IDS_MENURELOCATE,			IDS_MENUDESCRELOCATE,
//	ITEMIS_INSVN|ITEMIS_FOLDER|ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, ITEMIS_FOLDERINSVN|ITEMIS_ONLYONE, 0, 0, 0, 0, 0 },

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

	{ ShellMenuCreateRepos,					MENUCREATEREPOS,	IDI_CREATEREPOS,		IDS_MENUCREATEREPOS,		IDS_MENUDESCCREATEREPOS,
	ITEMIS_FOLDER, ITEMIS_INSVN|ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuAdd,							MENUADD,			IDI_ADD,				IDS_MENUADD,				IDS_MENUDESCADD,
	ITEMIS_INVERSIONEDFOLDER, ITEMIS_INSVN, ITEMIS_INSVN|ITEMIS_FOLDER, 0, ITEMIS_IGNORED, 0, ITEMIS_DELETED, ITEMIS_FOLDER|ITEMIS_ONLYONE },

//	{ ShellMenuAddAsReplacement,			MENUADD,			IDI_ADD,				IDS_MENUADDASREPLACEMENT,	IDS_MENUADDASREPLACEMENT,
//	ITEMIS_DELETED|ITEMIS_ONLYONE, ITEMIS_FOLDER, 0, 0, 0, 0, 0, 0 },

//	{ ShellMenuImport,						MENUIMPORT,			IDI_IMPORT,				IDS_MENUIMPORT,				IDS_MENUDESCIMPORT,
//	ITEMIS_FOLDER, ITEMIS_INSVN, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuBlame,						MENUBLAME,			IDI_BLAME,				IDS_MENUBLAME,				IDS_MENUDESCBLAME,
	ITEMIS_INSVN|ITEMIS_ONLYONE, ITEMIS_FOLDER|ITEMIS_ADDED, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuIgnoreSub,					MENUIGNORE,			IDI_IGNORE,				IDS_MENUIGNORE,				IDS_MENUDESCIGNORE,
	ITEMIS_INVERSIONEDFOLDER, ITEMIS_IGNORED|ITEMIS_INSVN|ITEMIS_WCROOT, 0, 0, 0, 0, 0, 0 },

    { ShellMenuDeleteIgnoreSub,             MENUIGNORE,         IDI_IGNORE,             IDS_MENUDELETEIGNORE,       IDS_MENUDESCDELETEIGNORE,
    ITEMIS_INVERSIONEDFOLDER|ITEMIS_INSVN, ITEMIS_IGNORED|ITEMIS_WCROOT, 0, 0, 0, 0, 0, 0 },

	// no support for this atm since we do not use "ignoredprops"-vector in ContextMenu.cpp
//	{ ShellMenuUnIgnoreSub,					MENUIGNORE,			IDI_IGNORE,				IDS_MENUUNIGNORE,			IDS_MENUDESCUNIGNORE,
//	ITEMIS_IGNORED, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

	{ ShellMenuSubAdd,				    MENUSUBADD,				IDI_ADD,				IDS_MENUSUBADD,				IDS_MENUSUBADD,
	ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuUpdateExt,					MENUUPDATEEXT,		IDI_UPDATE,				IDS_MENUUPDATEEXT,			IDS_MENUDESCUPDATEEXT,
	ITEMIS_FOLDERINSVN|ITEMIS_SUBMODULECONTAINER, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellMenuSubSync,					MENUSUBSYNC,			IDI_MENUSYNC,				IDS_MENUSUBSYNC,			IDS_MENUSUBSYNC,
	ITEMIS_FOLDERINSVN|ITEMIS_SUBMODULECONTAINER, 0, 0, 0, 0, 0, 0, 0 },



	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

//	{ ShellMenuCherryPick,					MENUCHERRYPICK,		IDI_CREATEPATCH,		IDS_MENUCHERRYPICK,		IDS_MENUDESCCREATEPATCH,
//	ITEMIS_INSVN, ITEMIS_NORMAL, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	{ ShellMenuFormatPatch,					MENUFORMATPATCH,	IDI_CREATEPATCH,		IDS_MENUFORMATPATCH,		IDS_MENUDESCCREATEPATCH,
	ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0, 0, 0 },

	// Really apply patch
	{ ShellMenuImportPatch,					MENUIMPORTPATCH,	IDI_PATCH,				IDS_MENUIMPORTPATCH,		IDS_MENUDESCIMPORTPATCH,
	ITEMIS_PATCHFILE, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },


//	{ ShellMenuCreatePatch,					MENUCREATEPATCH,	IDI_CREATEPATCH,		IDS_MENUCREATEPATCH,		IDS_MENUDESCCREATEPATCH,
//	ITEMIS_INSVN, ITEMIS_NORMAL, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

	// Review Patch
	{ ShellMenuApplyPatch,					MENUAPPLYPATCH,		IDI_PATCH,				IDS_MENUAPPLYPATCH,			IDS_MENUDESCAPPLYPATCH,
	ITEMIS_PATCHFILE|ITEMIS_ONLYONE, 0, ITEMIS_EXTENDED|ITEMIS_ONLYONE, ITEMIS_FOLDER, 0, 0, 0, 0 },

	{ ShellMenuSendMail,					MENUSENDMAIL,		IDI_MENUSENDMAIL,			IDS_MENUSENDMAIL,			IDS_MENUDESSENDMAIL,
	ITEMIS_PATCHFILE, 0, ITEMIS_EXTENDED, ITEMIS_FOLDER, 0, 0, 0, 0 },

//	{ ShellMenuProperties,					MENUPROPERTIES,		IDI_PROPERTIES,			IDS_MENUPROPERTIES,			IDS_MENUDESCPROPERTIES,
//	ITEMIS_INSVN, 0, ITEMIS_FOLDERINSVN, 0, 0, 0, 0, 0 },

// we do not support paste atm
//	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},
//	{ ShellMenuClipPaste,					MENUCLIPPASTE,		IDI_CLIPPASTE,			IDS_MENUCLIPPASTE,			IDS_MENUDESCCLIPPASTE,
//	ITEMIS_INSVN|ITEMIS_FOLDER|ITEMIS_PATHINCLIPBOARD, 0, 0, 0, 0, 0, 0, 0 },

	{ ShellSeparator, 0, 0, 0, 0, 0, 0, 0, 0},

	{ ShellMenuSettings,					MENUSETTINGS,		IDI_SETTINGS,			IDS_MENUSETTINGS,			IDS_MENUDESCSETTINGS,
	ITEMIS_FOLDER, 0, 0, ITEMIS_FOLDER, 0, 0, 0, 0 },
	{ ShellMenuHelp,						MENUHELP,			IDI_HELP,				IDS_MENUHELP,				IDS_MENUDESCHELP,
	ITEMIS_FOLDER, 0, 0, ITEMIS_FOLDER, 0, 0, 0, 0 },
	{ ShellMenuAbout,						MENUABOUT,			IDI_ABOUT,				IDS_MENUABOUT,				IDS_MENUDESCABOUT,
	ITEMIS_FOLDER, 0, 0, ITEMIS_FOLDER, 0, 0, 0, 0 },

	// the sub menus - they're not added like the the commands, therefore the menu ID is zero
	// but they still need to be in here, because we use the icon and string information anyway.
	{ ShellSubMenu,							NULL,				IDI_APP,				IDS_MENUSUBMENU,			0,
	0, 0, 0, 0, 0, 0, 0, 0 },
	{ ShellSubMenuFile,						NULL,				IDI_MENUFILE,			IDS_MENUSUBMENU,			0,
	0, 0, 0, 0, 0, 0, 0, 0 },
	{ ShellSubMenuFolder,					NULL,				IDI_MENUFOLDER,			IDS_MENUSUBMENU,			0,
	0, 0, 0, 0, 0, 0, 0, 0 },
	{ ShellSubMenuLink,						NULL,				IDI_MENULINK,			IDS_MENUSUBMENU,			0,
	0, 0, 0, 0, 0, 0, 0, 0 },
	{ ShellSubMenuMultiple,					NULL,				IDI_MENUMULTIPLE,		IDS_MENUSUBMENU,			0,
	0, 0, 0, 0, 0, 0, 0, 0 },
	// mark the last entry to tell the loop where to stop iterating over this array
	{ ShellMenuLastEntry,					0,					0,						0,							0,
	0, 0, 0, 0, 0, 0, 0, 0 },
};
