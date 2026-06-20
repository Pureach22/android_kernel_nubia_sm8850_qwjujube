__int64 __fastcall platform_mpam_enable_monitor_store(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w9
  int v6; // w10
  __int64 v7; // x1
  __int64 v8; // x8
  const char *v10; // x1
  _DWORD v11[2]; // [xsp+Ch] [xbp-24h] BYREF
  __int64 v12; // [xsp+14h] [xbp-1Ch]
  __int64 v13; // [xsp+1Ch] [xbp-14h]
  _BYTE v14[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+28h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD *)(a1 + 136);
  v6 = *(_DWORD *)(a1 + 140);
  v14[0] = 0;
  v13 = 0;
  v12 = 0;
  v11[0] = v5;
  v11[1] = v6;
  if ( (unsigned int)kstrtobool(a2, v14) )
  {
    printk(&unk_6E0A, v7);
    goto LABEL_9;
  }
  if ( (v14[0] & 1) != 0 )
  {
    if ( (*(_BYTE *)(a1 + 148) & 1) != 0 )
      goto LABEL_9;
    v8 = 1;
  }
  else
  {
    if ( (*(_BYTE *)(a1 + 148) & 1) == 0 )
      goto LABEL_9;
    v8 = 0;
  }
  v13 = v8;
  if ( (unsigned int)qcom_mpam_set_platform_bw_monitor(v11) )
  {
    if ( v14[0] )
      v10 = "enable";
    else
      v10 = "disable";
    printk(&unk_6DC5, v10);
  }
  else
  {
    *(_BYTE *)(a1 + 148) = v14[0];
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return a3;
}
