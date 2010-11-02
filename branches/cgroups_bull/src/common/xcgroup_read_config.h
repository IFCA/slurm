/*****************************************************************************\
 *  xcgroup_read_config.h - functions and declarations for reading cgroup.conf
 *****************************************************************************
 *  Copyright (C) 2009 CEA/DAM/DIF
 *  Written by Matthieu Hautreux <matthieu.hautreux@cea.fr>
 *
 *  This file is part of SLURM, a resource management program.
 *  For details, see <https://computing.llnl.gov/linux/slurm/>.
 *  Please also read the included file: DISCLAIMER.
 *
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission
 *  to link the code of portions of this program with the OpenSSL library under
 *  certain conditions as described in each individual source file, and
 *  distribute linked combinations including the two. You must obey the GNU
 *  General Public License in all respects for all of the code used other than
 *  OpenSSL. If you modify file(s) with this exception, you may extend this
 *  exception to your version of the file(s), but you are not obligated to do
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in
 *  the program, then also delete it here.
 *
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#ifndef _CGROUP_READ_CONFIG_H
#define _CGROUP_READ_CONFIG_H

#if HAVE_CONFIG_H
#  include "config.h"
#if HAVE_INTTYPES_H
#  include <inttypes.h>
#else  /* !HAVE_INTTYPES_H */
#  if HAVE_STDINT_H
#    include <stdint.h>
#  endif
#endif  /* HAVE_INTTYPES_H */
#else   /* !HAVE_CONFIG_H */
#include <stdint.h>
#endif  /* HAVE_CONFIG_H */


/* Slurm cgroup plugins configuration parameters */
typedef struct slurm_cgroup_conf {

	bool      cgroup_automount;
	char *    cgroup_subsystems;
	char *    cgroup_release_agent;

	char *    user_cgroup_params;
	char *    job_cgroup_params;
	char *    jobstep_cgroup_params;
	char *    task_cgroup_params;

	uint16_t  task_bind_type;

	bool      constrain_ram_space;
	uint32_t  allowed_ram_space;

	bool      constrain_swap_space;
	uint32_t  allowed_swap_space;

	bool      memlimit_enforcement;
	uint32_t  memlimit_threshold;

} slurm_cgroup_conf_t;

extern slurm_cgroup_conf_t *slurm_cgroup_conf;

/*
 * read_slurm_cgroup_conf - load the Slurm cgroup configuration from the
 *      cgroup.conf  file.
 *      This function can be called more than once if so desired.
 * RET SLURM_SUCCESS if no error, otherwise an error code
 */
extern int read_slurm_cgroup_conf(void);

/*
 * free_slurm_cgroup_conf - free storage associated with the global variable
 *	slurm_cgroup_conf
 */
extern void free_slurm_cgroup_conf(void);

#endif /* !_DBD_READ_CONFIG_H */