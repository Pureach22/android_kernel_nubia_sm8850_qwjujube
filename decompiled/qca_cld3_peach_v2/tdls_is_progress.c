__int64 __fastcall tdls_is_progress(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 result; // x0
  const char *v14; // x2
  _QWORD v15[2]; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  if ( !a1 )
  {
    v14 = "%s: invalid tdls vdev object";
    goto LABEL_7;
  }
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 216LL);
  if ( !v11 || (v12 = *(_QWORD *)(v11 + 80)) == 0 )
  {
    v14 = "%s: invalid psoc";
LABEL_7:
    qdf_trace_msg(0, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "tdls_is_progress", v15[0]);
    result = 0;
    goto LABEL_8;
  }
  LOBYTE(v15[0]) = a3;
  v15[1] = a2;
  v16 = 0;
  wlan_objmgr_iterate_obj_list(v12, 2, tdls_find_progress_peer_handler, (__int64)v15, 0, 0x11u);
  result = v16;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
