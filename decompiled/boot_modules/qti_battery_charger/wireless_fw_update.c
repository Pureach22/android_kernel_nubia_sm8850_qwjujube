__int64 __fastcall wireless_fw_update(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v5; // w9
  unsigned int v6; // w0
  int v7; // w10
  __int64 v8; // x2
  unsigned int v9; // w20
  unsigned int v11; // w0
  __int64 v12; // x2
  unsigned __int64 v13; // x20
  _QWORD *v14; // x0
  unsigned int v15; // w0
  __int64 v16; // x2
  void *v17; // x0
  _QWORD *v18; // x1
  unsigned int v19; // w0
  __int64 v20; // x0
  __int64 v21; // x2
  _QWORD *v22; // [xsp+8h] [xbp-28h] BYREF
  __int64 v23; // [xsp+10h] [xbp-20h] BYREF
  int v24; // [xsp+18h] [xbp-18h]
  __int64 v25; // [xsp+1Ch] [xbp-14h]
  int v26; // [xsp+24h] [xbp-Ch]
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[67];
  v22 = nullptr;
  if ( !v3 )
  {
    printk(&unk_11E45, "wireless_fw_update", a3);
    v9 = -22;
    goto LABEL_9;
  }
  pm_stay_awake(*a1);
  v5 = *((_DWORD *)a1 + 109);
  v25 = 0;
  v26 = 0;
  v23 = 0x10000800ALL;
  v24 = v5;
  v6 = battery_chg_write((__int64)a1, (__int64)&v23, 0x18u, 0x3E8u);
  if ( (v6 & 0x80000000) != 0 )
  {
    v9 = v6;
    goto LABEL_8;
  }
  if ( *(_DWORD *)a1[53] )
    goto LABEL_11;
  v7 = *((_DWORD *)a1 + 97);
  v26 = 0;
  v25 = 0x400000000LL;
  v23 = 0x10000800ALL;
  v24 = v7;
  v9 = battery_chg_write((__int64)a1, (__int64)&v23, 0x18u, 0x3E8u);
  if ( (v9 & 0x80000000) == 0 )
  {
    if ( *(_DWORD *)(a1[47] + 16LL) >> 3 <= 0x270u )
    {
      printk(&unk_FD92, "wireless_fw_update", v8);
      v9 = -22;
      goto LABEL_8;
    }
LABEL_11:
    v11 = firmware_request_nowarn(&v22, a1[67], *a1);
    if ( v11 )
    {
      v9 = v11;
      printk(&unk_113D3, "wireless_fw_update", v11);
      goto LABEL_8;
    }
    if ( v22 && v22[1] && (v13 = *v22) != 0 )
    {
      if ( v13 >> 14 )
      {
        v15 = wireless_fw_version_get(a1);
        v9 = wireless_fw_check_for_update(a1, v15, v13);
        if ( (v9 & 0x80000000) != 0 )
        {
          v17 = &unk_101CB;
        }
        else
        {
          if ( (*((_BYTE *)a1 + 1078) & 1) == 0 )
          {
            printk(&unk_106AF, "wireless_fw_update", v16);
            goto LABEL_17;
          }
          msleep(1000);
          v18 = v22;
          *((_DWORD *)a1 + 80) = 0;
          v19 = wireless_fw_send_firmware(a1, v18);
          if ( (v19 & 0x80000000) == 0 )
          {
            v20 = _msecs_to_jiffies(*((unsigned int *)a1 + 272));
            if ( (unsigned int)wait_for_completion_timeout(a1 + 40, v20) )
            {
              printk(&unk_116DE, "wireless_fw_update", v21);
              v9 = 0;
            }
            else
            {
              printk(&unk_FB9F, "wireless_fw_update", v21);
              v9 = -110;
            }
            goto LABEL_17;
          }
          v9 = v19;
          v17 = &unk_103B1;
        }
        printk(v17, "wireless_fw_update", v9);
LABEL_17:
        v14 = v22;
        *((_WORD *)a1 + 542) = 0;
        release_firmware(v14);
        goto LABEL_8;
      }
      printk(&unk_11812, "wireless_fw_update", v13);
    }
    else
    {
      printk(&unk_11403, "wireless_fw_update", v12);
    }
    v9 = -22;
    goto LABEL_17;
  }
LABEL_8:
  pm_relax(*a1);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v9;
}
