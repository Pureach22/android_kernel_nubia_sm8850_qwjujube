__int64 __fastcall u_mac_post_ctrl_msg(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int16 v10; // w4
  int v11; // w8
  unsigned int v12; // w19
  unsigned int v13; // w0
  __int64 v15; // [xsp+8h] [xbp-38h] BYREF
  unsigned __int16 *v16; // [xsp+10h] [xbp-30h]
  __int64 v17; // [xsp+18h] [xbp-28h]
  __int64 v18; // [xsp+20h] [xbp-20h]
  __int64 v19; // [xsp+28h] [xbp-18h]
  __int64 v20; // [xsp+30h] [xbp-10h]
  __int64 v21; // [xsp+38h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a2;
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v11 = v10 & 0xFF00;
  v16 = a2;
  v15 = v10;
  if ( v11 == 5120 )
  {
    v13 = sme_post_pe_message(a1, (unsigned __int16 *)&v15);
LABEL_8:
    v12 = v13;
    if ( !v13 )
      goto LABEL_13;
    goto LABEL_12;
  }
  if ( v11 == 4864 )
  {
    v13 = lim_post_msg_api(a1, (unsigned __int16 *)&v15);
    goto LABEL_8;
  }
  if ( v11 != 4096 )
  {
    qdf_trace_msg(0x36u, 8u, "%s: Unknown message type = 0x%X", a3, a4, a5, a6, a7, a8, a9, a10, "u_mac_post_ctrl_msg");
    goto LABEL_11;
  }
  if ( (unsigned int)scheduler_post_message_debug(
                       0x36u,
                       0x36u,
                       54,
                       (unsigned __int16 *)&v15,
                       0x35u,
                       (__int64)"wma_post_ctrl_msg") )
  {
LABEL_11:
    v12 = 16;
LABEL_12:
    _qdf_mem_free((__int64)v16);
    goto LABEL_13;
  }
  v12 = 0;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v12;
}
