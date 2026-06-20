__int64 __fastcall p2p_set_mac_filter(
        __int64 a1,
        unsigned int a2,
        unsigned __int8 *a3,
        unsigned int a4,
        char a5,
        __int64 a6,
        __int64 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  char v21; // w24
  __int64 v22; // x7
  int v23; // w8
  int v24; // w9
  int v25; // w10
  __int64 v26; // x0
  __int64 v27; // x26
  __int64 result; // x0
  unsigned int v29; // w19
  __int64 v30; // [xsp+18h] [xbp-38h] BYREF
  __int64 v31; // [xsp+20h] [xbp-30h]
  __int64 (__fastcall *v32)(unsigned __int16 *, double, double, double, double, double, double, double, double); // [xsp+28h] [xbp-28h]
  __int64 v33; // [xsp+30h] [xbp-20h]
  __int64 v34; // [xsp+38h] [xbp-18h]
  __int64 v35; // [xsp+40h] [xbp-10h]
  __int64 v36; // [xsp+48h] [xbp-8h]

  v21 = a5 & 1;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v34 = 0;
  v35 = 0;
  v32 = nullptr;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( a3 )
  {
    v22 = *a3;
    v23 = a3[1];
    v24 = a3[2];
    v25 = a3[5];
  }
  else
  {
    v24 = 0;
    v22 = 0;
    v23 = 0;
    v25 = 0;
  }
  qdf_trace_msg(
    0x4Eu,
    8u,
    "%s: random_mac:vdev %d freq %d set %d %02x:%02x:%02x:**:**:%02x",
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    a14,
    a15,
    "p2p_set_mac_filter",
    a2,
    a4,
    a5 & 1,
    v22,
    v23,
    v24,
    v25,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36);
  v26 = _qdf_mem_malloc(0x30u, "p2p_set_mac_filter", 2889);
  if ( v26 )
  {
    v27 = v26;
    *(_QWORD *)v26 = a1;
    *(_DWORD *)(v26 + 8) = a2;
    *(_DWORD *)(v26 + 20) = a4;
    qdf_mem_copy((void *)(v26 + 12), a3, 6u);
    *(_BYTE *)(v27 + 24) = v21;
    *(_QWORD *)(v27 + 32) = a6;
    *(_QWORD *)(v27 + 40) = a7;
    LOWORD(v30) = 6;
    v31 = v27;
    v32 = p2p_process_cmd;
    result = scheduler_post_message_debug(
               0x4Eu,
               0x4Eu,
               72,
               (unsigned __int16 *)&v30,
               0xB59u,
               (__int64)"p2p_set_mac_filter");
    if ( (_DWORD)result )
    {
      v29 = result;
      _qdf_mem_free(v27);
      result = v29;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
