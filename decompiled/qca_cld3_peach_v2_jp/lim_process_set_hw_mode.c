__int64 __fastcall lim_process_set_hw_mode(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // w8
  __int64 v22; // x20
  __int64 result; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // [xsp+8h] [xbp-68h] BYREF
  __int64 v33; // [xsp+10h] [xbp-60h]
  __int64 v34; // [xsp+18h] [xbp-58h]
  __int64 v35; // [xsp+20h] [xbp-50h]
  __int64 v36; // [xsp+28h] [xbp-48h]
  __int64 v37; // [xsp+30h] [xbp-40h]
  __int64 v38; // [xsp+38h] [xbp-38h] BYREF
  _DWORD *v39; // [xsp+40h] [xbp-30h]
  __int64 v40; // [xsp+48h] [xbp-28h]
  __int64 v41; // [xsp+50h] [xbp-20h]
  __int64 v42; // [xsp+58h] [xbp-18h]
  __int64 v43; // [xsp+60h] [xbp-10h]
  __int64 v44; // [xsp+68h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = nullptr;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  if ( a2 )
  {
    v12 = (_DWORD *)_qdf_mem_malloc(0x30u, "lim_process_set_hw_mode", 187);
    if ( v12 )
    {
      *v12 = *(_DWORD *)(a2 + 8);
      v21 = *(_DWORD *)(a2 + 24);
      v39 = v12;
      v22 = (__int64)v12;
      LOWORD(v38) = 4457;
      v12[4] = v21;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Posting SIR_HAL_SOC_SET_HW_MOD to WMA",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "lim_process_set_hw_mode");
      result = scheduler_post_message_debug(
                 0x35u,
                 0x36u,
                 54,
                 (unsigned __int16 *)&v38,
                 0xCBu,
                 (__int64)"lim_process_set_hw_mode");
      if ( !(_DWORD)result )
        goto LABEL_8;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: scheduler_post_msg failed!(err=%d)",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "lim_process_set_hw_mode",
        (unsigned int)result);
      _qdf_mem_free(v22);
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Set HW mode param is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "lim_process_set_hw_mode");
  }
  result = _qdf_mem_malloc(0x2Cu, "lim_process_set_hw_mode", 212);
  if ( result )
  {
    *(_DWORD *)(result + 8) = 0;
    *(_QWORD *)result = 2;
    v33 = result;
    LOWORD(v32) = 5226;
    HIDWORD(v32) = 0;
    result = sys_process_mmh_msg(a1, &v32);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
