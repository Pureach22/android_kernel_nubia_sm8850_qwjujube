__int64 __fastcall cdsprm_resmgr_pdkill_config(int a1)
{
  __int64 result; // x0
  int v3; // w20
  __int64 v4; // x0
  unsigned int v5; // w0
  unsigned int v6; // w19
  __int64 v7; // [xsp+4h] [xbp-11Ch] BYREF
  int v8; // [xsp+Ch] [xbp-114h]
  int v9; // [xsp+10h] [xbp-110h]
  _BYTE v10[260]; // [xsp+14h] [xbp-10Ch] BYREF
  __int64 v11; // [xsp+118h] [xbp-8h]

  result = 4294967274LL;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( qword_A350 && gcdsprm[0] >= 3u )
  {
    v3 = a1;
    memset(v10, 0, sizeof(v10));
    v4 = *(_QWORD *)(qword_A350 + 968);
    v8 = 16;
    v9 = v3;
    v7 = 0x200000114LL;
    v5 = rpmsg_send(v4, &v7, 276);
    if ( v5 )
    {
      v6 = v5;
      printk(&unk_BEE4);
      result = v6;
    }
    else
    {
      dword_99AC = v3;
      printk(&unk_B368);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
