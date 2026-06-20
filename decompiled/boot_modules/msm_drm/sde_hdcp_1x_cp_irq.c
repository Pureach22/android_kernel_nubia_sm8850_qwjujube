__int64 __fastcall sde_hdcp_1x_cp_irq(__int64 a1)
{
  int v1; // w8
  __int64 result; // x0
  void *v4; // x0
  int v5; // w23
  unsigned int v6; // w20
  char *v7; // x21
  int v8; // w25
  int v9; // w8
  int v10; // w8
  __int64 v11; // x1
  int v12; // w8
  void (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x0
  char v15; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v16[4]; // [xsp+10h] [xbp-10h] BYREF
  char v17[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 1000);
    v16[0] = 0;
    if ( v1 == 1 && (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 936), 513, v16, 1) != 1 )
    {
      printk(&unk_26ECF1, "sde_hdcp_1x_read");
      printk(&unk_2677C0, "sde_hdcp_1x_is_cp_irq_raised");
      if ( (v16[0] & 4) == 0 )
        goto LABEL_5;
    }
    else if ( (v16[0] & 4) == 0 )
    {
LABEL_5:
      result = 4294967274LL;
      goto LABEL_25;
    }
    if ( *(_DWORD *)(a1 + 1000) != 1 )
    {
LABEL_24:
      result = 0;
      goto LABEL_25;
    }
    v5 = *(_DWORD *)(a1 + 1284);
    v6 = *(_DWORD *)(a1 + 1280);
    v7 = &v15;
    do
    {
      if ( v5 >= 15 )
        v8 = 15;
      else
        v8 = v5;
      if ( v8 != (unsigned int)drm_dp_dpcd_read(*(_QWORD *)(a1 + 936), v6, v7, v8) )
      {
        printk(&unk_26ECF1, "sde_hdcp_1x_read");
        v4 = &unk_255B7A;
        goto LABEL_7;
      }
      v5 -= v8;
      v7 += v8;
      v6 += v8;
    }
    while ( v5 > 0 );
    if ( (v15 & 0xC) == 0 )
    {
      if ( (v15 & 2) != 0 )
      {
        *(_BYTE *)(a1 + 32) = 1;
        complete_all(a1 + 840);
      }
      else if ( (v15 & 1) != 0 )
      {
        *(_BYTE *)(a1 + 34) = 1;
      }
LABEL_21:
      v9 = *(_DWORD *)(a1 + 1000);
      v17[0] = 4;
      if ( v9 == 1 && (unsigned int)drm_dp_dpcd_write(*(_QWORD *)(a1 + 936), 513, v17, 1) != 1 )
      {
        printk(&unk_26ECF1, "sde_hdcp_1x_write");
        printk(&unk_23DEC1, "sde_hdcp_1x_clear_cp_irq");
      }
      goto LABEL_24;
    }
    printk(&unk_26B1F0, "sde_hdcp_1x_cp_irq");
    v10 = *(_DWORD *)(a1 + 40);
    *(_BYTE *)(a1 + 33) = 1;
    if ( v10 )
      *(_DWORD *)(a1 + 40) = 3;
    complete_all(a1 + 840);
    if ( *(_DWORD *)(a1 + 40) == 2 )
    {
      msm_hdcp_cache_repeater_topology(*(_QWORD *)(a1 + 872), (const void *)(a1 + 44));
      msm_hdcp_notify_topology(*(_QWORD *)(a1 + 872));
      v11 = *(_QWORD *)(a1 + 1440);
      if ( *(_DWORD *)(a1 + 40) == 2 )
      {
        *(_DWORD *)v11 = *(unsigned __int8 *)(a1 + 54);
        *(_DWORD *)(v11 + 4) = *(unsigned __int8 *)(a1 + 53);
        *(_DWORD *)(v11 + 8) = *(_DWORD *)(a1 + 696);
        v12 = *(_DWORD *)(a1 + 692);
        *(_QWORD *)(v11 + 16) = 0;
        *(_DWORD *)(v11 + 12) = v12;
LABEL_34:
        hdcp1_ops_notify(*(_QWORD *)(a1 + 1448));
        v13 = *(void (__fastcall **)(_QWORD))(a1 + 968);
        if ( v13 && *(_DWORD *)(a1 + 40) )
        {
          v14 = *(_QWORD *)(a1 + 960);
          if ( *((_DWORD *)v13 - 1) != -815732472 )
            __break(0x8228u);
          v13(v14);
        }
        goto LABEL_21;
      }
    }
    else
    {
      v11 = *(_QWORD *)(a1 + 1440);
    }
    *(_QWORD *)(v11 + 8) = 0;
    *(_QWORD *)(v11 + 16) = 0;
    *(_QWORD *)v11 = 0;
    goto LABEL_34;
  }
  v4 = &unk_255B25;
LABEL_7:
  printk(v4, "sde_hdcp_1x_cp_irq");
  result = 4294967274LL;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
