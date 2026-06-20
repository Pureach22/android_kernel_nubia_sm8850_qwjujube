__int64 __fastcall lim_prepare_n_send_ttlm_action_rsp_frame(__int64 result, char a2, int a3, const void *a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 v6; // [xsp+0h] [xbp-20h] BYREF
  _QWORD v7[3]; // [xsp+8h] [xbp-18h] BYREF

  v7[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(result + 784);
  v7[0] = 0;
  v7[1] = 0;
  v6 = 0;
  if ( v4 )
  {
    v5 = result;
    BYTE4(v7[0]) = a2;
    LODWORD(v7[0]) = a3;
    qdf_mem_copy((char *)v7 + 5, a4, 6u);
    result = ttlm_sm_deliver_event(*(_QWORD *)(v5 + 784), 3, 24, &v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
