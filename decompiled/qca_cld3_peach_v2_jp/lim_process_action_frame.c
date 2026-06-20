__int64 __fastcall lim_process_action_frame(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w22
  unsigned __int8 *v12; // x24
  __int64 v13; // x25
  const char *v14; // x2
  const char *v15; // x3
  unsigned int v16; // w1
  __int64 v17; // x4
  __int64 result; // x0
  unsigned int v21; // w23
  __int64 v22; // x4
  __int64 v23; // x20
  _WORD v24[2]; // [xsp+10h] [xbp-10h] BYREF
  int v25; // [xsp+14h] [xbp-Ch]
  __int64 v26; // [xsp+18h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_DWORD *)(a2 + 40);
  v13 = *(_QWORD *)(a2 + 16);
  v12 = *(unsigned __int8 **)(a2 + 24);
  v25 = 446328656;
  if ( v11 <= 1 )
  {
    v14 = "%s: frame_len %d less than Action Frame Hdr size";
    v15 = "lim_process_action_frame";
    v16 = 8;
    v17 = v11;
LABEL_3:
    result = qdf_trace_msg(0x35u, v16, v14, a4, a5, a6, a7, a8, a9, a10, a11, v15, v17);
    goto LABEL_4;
  }
  result = wlan_mgmt_is_rmf_mgmt_action_frame(*v12);
  if ( (result & 1) != 0 )
  {
    v21 = *v12;
    v24[0] = 0;
    result = dph_lookup_hash_entry(a4, a5, a6, a7, a8, a9, a10, a11, a1, (unsigned __int8 *)(v13 + 10), v24, a3 + 360);
    if ( result )
    {
      if ( (*(_WORD *)result & 0x400) != 0 && (*(_WORD *)v13 & 0x4000) == 0 )
      {
        v14 = "%s: Dropping unprotected Action category: %d frame since RMF is enabled";
        v15 = "lim_drop_unprotected_action_frame";
        v16 = 2;
        v17 = v21;
        goto LABEL_3;
      }
    }
  }
  v22 = *v12;
  if ( (v22 & 0x80) == 0 )
    __asm { BR              X9 }
  v23 = jiffies;
  if ( lim_process_action_frame___last_ticks - jiffies + 125 < 0 )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Action category: %d not handled",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_action_frame");
    lim_process_action_frame___last_ticks = v23;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
