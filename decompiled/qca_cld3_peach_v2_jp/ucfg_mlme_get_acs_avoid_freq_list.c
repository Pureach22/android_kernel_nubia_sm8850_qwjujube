__int64 __fastcall ucfg_mlme_get_acs_avoid_freq_list(__int64 a1, void *a2, _BYTE *a3)
{
  __int64 psoc_ext_obj_fl; // x0
  int v6; // w8
  __int64 result; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = 0;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( psoc_ext_obj_fl )
  {
    v6 = *(unsigned __int8 *)(psoc_ext_obj_fl + 6382);
    *a3 = v6;
    qdf_mem_copy(a2, (const void *)(psoc_ext_obj_fl + 6182), (unsigned int)(2 * v6));
    result = 0;
  }
  else
  {
    qdf_uint16_array_parse(&unk_8B9E43, (__int64)a2, 100, v16);
    *a3 = v16[0];
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: Failed to get MLME Obj",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "ucfg_mlme_get_acs_avoid_freq_list");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
