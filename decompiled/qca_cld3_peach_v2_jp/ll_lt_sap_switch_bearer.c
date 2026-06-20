__int64 __fastcall ll_lt_sap_switch_bearer(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        int a6,
        __int64 a7)
{
  unsigned __int8 v12; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w1
  unsigned int v23; // w22
  __int64 v25; // [xsp+0h] [xbp-30h] BYREF
  unsigned int v26; // [xsp+8h] [xbp-28h]
  unsigned int v27; // [xsp+Ch] [xbp-24h]
  __int64 v28; // [xsp+10h] [xbp-20h]
  int v29; // [xsp+18h] [xbp-18h]
  int v30; // [xsp+1Ch] [xbp-14h]
  __int64 v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v12 = a2;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  LODWORD(v25) = a2;
  HIDWORD(v25) = ll_lt_sap_bearer_switch_get_id(a1);
  v26 = a3;
  v27 = a4;
  v28 = a5;
  v29 = a6;
  v31 = a7;
  if ( a3 )
  {
    if ( a3 != 1 )
    {
      v23 = 4;
      goto LABEL_8;
    }
    v22 = 0;
  }
  else
  {
    v22 = 1;
  }
  v23 = bs_sm_deliver_event(a1, v22, 0x28u, (__int64)&v25);
  if ( v23 )
  {
    a3 = v26;
    a4 = v27;
    v12 = v25;
LABEL_8:
    qdf_trace_msg(
      0xA1u,
      2u,
      "%s: vdev %d beaer_switch failed for req_type %d source %d status %d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "ll_lt_sap_switch_bearer",
      v12,
      a3,
      a4,
      v23,
      v25);
  }
  _ReadStatusReg(SP_EL0);
  return v23;
}
