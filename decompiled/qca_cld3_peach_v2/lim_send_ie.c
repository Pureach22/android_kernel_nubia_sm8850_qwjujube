__int64 __fastcall lim_send_ie(int a1, unsigned __int8 a2, int a3, const void *a4, unsigned int a5)
{
  _DWORD *v10; // x0
  __int64 v11; // x19
  void *v12; // x0
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  __int64 v23; // [xsp+8h] [xbp-38h] BYREF
  __int64 v24; // [xsp+10h] [xbp-30h]
  __int64 v25; // [xsp+18h] [xbp-28h]
  __int64 v26; // [xsp+20h] [xbp-20h]
  __int64 v27; // [xsp+28h] [xbp-18h]
  __int64 v28; // [xsp+30h] [xbp-10h]
  __int64 v29; // [xsp+38h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = 0;
  v23 = 0;
  v24 = 0;
  v10 = (_DWORD *)_qdf_mem_malloc(a5 + 24LL, "lim_send_ie", 5850);
  if ( v10 )
  {
    v11 = (__int64)v10;
    v10[2] = a5;
    v10[3] = a3;
    *v10 = a1;
    v10[1] = a2;
    v12 = v10 + 6;
    *(_QWORD *)(v11 + 16) = v12;
    qdf_mem_copy(v12, a4, a5);
    LODWORD(v23) = 4462;
    v24 = v11;
    result = scheduler_post_message_debug(0x35u, 0x36u, 54, (unsigned __int16 *)&v23, 0x16ECu, (__int64)"lim_send_ie");
    if ( (_DWORD)result )
    {
      v22 = result;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Not able to post WMA_SET_IE_INFO to WMA",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_send_ie");
      _qdf_mem_free(v11);
      result = v22;
    }
  }
  else
  {
    result = 2;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
