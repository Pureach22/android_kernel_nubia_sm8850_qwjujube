__int64 __fastcall cdsprm_resmgr_pdkill_override_write(__int64 a1, int a2)
{
  unsigned int v3; // w20
  __int64 v4; // x0
  void *v5; // x0
  __int64 v7; // [xsp+4h] [xbp-11Ch] BYREF
  int v8; // [xsp+Ch] [xbp-114h]
  int v9; // [xsp+10h] [xbp-110h]
  _BYTE v10[260]; // [xsp+14h] [xbp-10Ch] BYREF
  __int64 v11; // [xsp+118h] [xbp-8h]

  v3 = -22;
  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( qword_A350 && gcdsprm[0] >= 3u )
  {
    memset(v10, 0, sizeof(v10));
    v4 = *(_QWORD *)(qword_A350 + 968);
    v8 = 16;
    v9 = a2;
    v7 = 0x200000114LL;
    v3 = rpmsg_send(v4, &v7, 276);
    if ( v3 )
    {
      v5 = &unk_BEE4;
    }
    else
    {
      v5 = &unk_B368;
      dword_99AC = a2;
    }
    printk(v5);
  }
  printk(&unk_B5B1);
  _ReadStatusReg(SP_EL0);
  return v3;
}
