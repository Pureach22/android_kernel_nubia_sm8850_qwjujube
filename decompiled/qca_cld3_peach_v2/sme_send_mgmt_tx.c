__int64 __fastcall sme_send_mgmt_tx(__int64 a1, char a2, const void *a3, unsigned int a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x0
  __int64 v18; // x22
  unsigned int v19; // w20
  __int64 v20; // [xsp+8h] [xbp-38h] BYREF
  __int64 v21; // [xsp+10h] [xbp-30h]
  __int64 v22; // [xsp+18h] [xbp-28h]
  __int64 v23; // [xsp+20h] [xbp-20h]
  __int64 v24; // [xsp+28h] [xbp-18h]
  __int64 v25; // [xsp+30h] [xbp-10h]
  __int64 v26; // [xsp+38h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = qdf_mutex_acquire(a1 + 12848);
  if ( !(_DWORD)result )
  {
    v24 = 0;
    v25 = 0;
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    qdf_trace_msg(0x34u, 8u, "%s: prepares auth frame", v9, v10, v11, v12, v13, v14, v15, v16, "sme_prepare_mgmt_tx");
    v17 = _qdf_mem_malloc((unsigned __int16)(a4 + 16), "sme_prepare_mgmt_tx", 5778);
    if ( v17 )
    {
      *(_WORD *)(v17 + 2) = a4 + 16;
      *(_WORD *)v17 = 5263;
      *(_BYTE *)(v17 + 4) = a2;
      v18 = v17;
      *(_QWORD *)(v17 + 8) = v17 + 16;
      qdf_mem_copy((void *)(v17 + 16), a3, a4);
      LOWORD(v20) = 5263;
      v21 = v18;
      v19 = scheduler_post_message_debug(
              0x34u,
              0x35u,
              53,
              (unsigned __int16 *)&v20,
              0x16A0u,
              (__int64)"sme_prepare_mgmt_tx");
    }
    else
    {
      v19 = 2;
    }
    qdf_mutex_release(a1 + 12848);
    result = v19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
