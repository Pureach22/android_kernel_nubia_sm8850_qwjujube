__int64 __fastcall csr_roam_wm_status_change_complete(__int64 a1, unsigned __int8 a2)
{
  __int64 active; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x21
  const char *v15; // x2
  __int64 v16; // x4
  unsigned int v17; // w1

  active = csr_nonscan_active_ll_peek_head(a1, 1);
  if ( active )
  {
    v13 = (_DWORD *)active;
    if ( *(_DWORD *)(active + 16) == 65538 )
    {
      if ( (csr_nonscan_active_ll_remove_entry(a1, active, 1) & 1) != 0 )
        return csr_release_command(a1, v13, v5, v6, v7, v8, v9, v10, v11, v12);
      v15 = "%s: vdev %d Failed to release command";
    }
    else
    {
      v15 = "%s: vdev %d LOST LINK command is not ACTIVE ...";
    }
    v16 = a2;
    v17 = 2;
  }
  else
  {
    v15 = "%s: vdev %d NO commands are ACTIVE ...";
    v16 = a2;
    v17 = 4;
  }
  return qdf_trace_msg(0x34u, v17, v15, v5, v6, v7, v8, v9, v10, v11, v12, "csr_roam_wm_status_change_complete", v16);
}
