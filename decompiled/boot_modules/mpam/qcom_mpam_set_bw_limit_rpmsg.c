__int64 __fastcall qcom_mpam_set_bw_limit_rpmsg(int a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  unsigned int v4; // w0
  __int64 v5; // x1
  unsigned int v6; // w19
  __int64 v7; // [xsp+Ch] [xbp-24h] BYREF
  int v8; // [xsp+14h] [xbp-1Ch]
  __int64 v9; // [xsp+18h] [xbp-18h]
  int v10; // [xsp+20h] [xbp-10h]
  int v11; // [xsp+24h] [xbp-Ch]
  __int64 v12; // [xsp+28h] [xbp-8h]

  result = 4294967277LL;
  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( rpmsgdev && cdsp_version )
  {
    v3 = *(_QWORD *)(rpmsgdev + 968);
    v9 = 0;
    v7 = 0x1C00000001LL;
    v8 = 1;
    v10 = 1;
    v11 = a1;
    v4 = rpmsg_send(v3, &v7, 28);
    if ( v4 )
    {
      v6 = v4;
      printk(&unk_6DAA, v4);
      result = v6;
    }
    else if ( wait_for_completion_timeout(&rpmsg_complete, 25) )
    {
      if ( HIDWORD(qword_6988) )
      {
        printk(&unk_6E3A, HIDWORD(qword_6988));
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
      printk(&unk_6D24, v5);
      cdsp_limit_cfg = -1;
      result = 4294967291LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
