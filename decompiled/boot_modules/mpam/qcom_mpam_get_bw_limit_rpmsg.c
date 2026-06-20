__int64 qcom_mpam_get_bw_limit_rpmsg()
{
  __int64 result; // x0
  __int64 v1; // x0
  unsigned int v2; // w0
  __int64 v3; // x1
  unsigned int v4; // w19
  __int64 v5; // [xsp+Ch] [xbp-24h] BYREF
  int v6; // [xsp+14h] [xbp-1Ch]
  __int64 v7; // [xsp+18h] [xbp-18h]
  __int64 v8; // [xsp+20h] [xbp-10h]
  __int64 v9; // [xsp+28h] [xbp-8h]

  result = 4294967277LL;
  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( rpmsgdev && cdsp_version )
  {
    v1 = *(_QWORD *)(rpmsgdev + 968);
    v7 = 0;
    v8 = 0;
    v5 = 0x1C00000002LL;
    v6 = 1;
    v2 = rpmsg_send(v1, &v5, 28);
    if ( v2 )
    {
      v4 = v2;
      printk(&unk_6CC0, v2);
      result = v4;
    }
    else if ( wait_for_completion_timeout(&rpmsg_complete, 25) )
    {
      if ( HIDWORD(qword_6988) )
      {
        printk(&unk_6C7E, HIDWORD(qword_6988));
        result = 4294967291LL;
      }
      else
      {
        result = 0;
        cdsp_limit_cfg = cdsp_status;
        dword_6948 = qword_6988;
      }
    }
    else
    {
      printk(&unk_6CFB, v3);
      cdsp_limit_cfg = -1;
      result = 4294967291LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
