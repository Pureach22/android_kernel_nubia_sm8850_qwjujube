__int64 __fastcall hfi_catalog_get_hfi_format(unsigned int *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x4
  __int64 v4; // x3
  __int64 *v5; // x9
  unsigned int *v6; // x8
  unsigned __int64 v7; // x10
  __int64 v8; // x8
  __int64 result; // x0

  if ( !a1 )
  {
    printk(&unk_23141E, "hfi_catalog_get_hfi_format");
    return 0xFFFFFFFFLL;
  }
  v3 = *((_QWORD *)a1 + 1);
  v4 = *a1;
  if ( v3 )
  {
    if ( (_DWORD)v4 == 875708993 )
    {
      if ( v3 == 0x500000000000001LL )
      {
        v6 = (unsigned int *)&unk_285F90;
        v5 = (_QWORD *)&_ksymtab_msm_dss_clean_io_mem;
        goto LABEL_50;
      }
      if ( v3 == 0x500000000000008LL )
      {
        v5 = nullptr;
        v6 = (unsigned int *)&sde_non_linear_fmt_map;
LABEL_50:
        v7 = 288;
        v4 = 875708993;
        goto LABEL_51;
      }
    }
    else if ( (int)v4 > 909199169 )
    {
      switch ( (_DWORD)v4 )
      {
        case 0x36314742:
          if ( v3 == 0x500000000000001LL )
          {
            v6 = (unsigned int *)&unk_285FC0;
            v4 = 909199170;
            v5 = (__int64 *)&_ksymtab_msm_dss_enable_vreg;
            v7 = 288;
            goto LABEL_51;
          }
          break;
        case 0x48344241:
          if ( v3 == 0x500000000000001LL )
          {
            v6 = (unsigned int *)&unk_285FB0;
            v5 = (_QWORD *)&unk_80;
            v7 = 288;
            goto LABEL_51;
          }
          if ( v3 == 0x500000000000010LL )
          {
            v6 = (unsigned int *)&unk_285F80;
            v7 = 288;
            v4 = 1211384385;
            v5 = (_QWORD *)&unk_50;
            goto LABEL_51;
          }
          break;
        case 0x48345241:
          v4 = 1211388481;
          if ( v3 == 0x500000000000010LL )
          {
            v6 = (unsigned int *)&unk_285F70;
            v5 = (_QWORD *)&unk_40;
            v7 = 288;
            goto LABEL_51;
          }
          goto LABEL_53;
      }
    }
    else
    {
      switch ( (_DWORD)v4 )
      {
        case 0x30334241:
          if ( v3 == 0x500000000000001LL )
          {
            v6 = (unsigned int *)&unk_285FA0;
            v5 = (_QWORD *)&unk_70;
            v7 = 288;
            goto LABEL_51;
          }
          if ( v3 == 0x500000000000008LL )
          {
            v6 = (unsigned int *)&unk_285F50;
            v4 = 808665665;
            v5 = (_QWORD *)&dword_20;
            v7 = 288;
            goto LABEL_51;
          }
          break;
        case 0x30334258:
          if ( v3 == 0x500000000000001LL )
          {
            v6 = (unsigned int *)&unk_285FE0;
            v5 = (_QWORD *)&unk_B0;
            v7 = 288;
            goto LABEL_51;
          }
          if ( v3 == 0x500000000000008LL )
          {
            v6 = (unsigned int *)&unk_285F60;
            v7 = 288;
            v4 = 808665688;
            v5 = (_QWORD *)&_ksymtab_dss_reg_dump;
            goto LABEL_51;
          }
          break;
        case 0x34324258:
          if ( v3 == 0x500000000000001LL )
          {
            v6 = (unsigned int *)&unk_285FD0;
            v5 = (_QWORD *)&unk_A0;
            v7 = 288;
            goto LABEL_51;
          }
          if ( v3 == 0x500000000000008LL )
          {
            v6 = (unsigned int *)&unk_285F40;
            v4 = 875709016;
            v5 = &qword_10;
            v7 = 288;
            goto LABEL_51;
          }
          break;
      }
    }
    if ( (_DWORD)v4 == 875708993 )
    {
      if ( v3 == 0x500000000000021LL )
      {
        v6 = (unsigned int *)&unk_285FF0;
        v5 = (_QWORD *)&_ksymtab_msm_dss_get_io_mem;
        goto LABEL_50;
      }
      if ( v3 == 0x500000000000201LL )
      {
        v6 = (unsigned int *)&unk_286000;
        v5 = (_QWORD *)&unk_D0;
        goto LABEL_50;
      }
    }
    else if ( (_DWORD)v4 == 842094158 )
    {
      v8 = v3 - 0x500000000000001LL;
      if ( (unsigned __int64)(v3 - 0x500000000000001LL) < 7 && ((0x47u >> v8) & 1) != 0 )
      {
        v5 = (&off_286050)[v8];
        v6 = (unsigned int *)*(&off_286088 + v8);
        v7 = 288;
        v4 = 842094158;
        goto LABEL_51;
      }
    }
LABEL_53:
    printk(&unk_2156F7, "hfi_catalog_get_hfi_format");
    return 0xFFFFFFFFLL;
  }
  v5 = nullptr;
  while ( 1 )
  {
    v6 = (unsigned int *)((char *)&sde_linear_fmt_map + (_QWORD)v5);
    if ( *(_DWORD *)((char *)&sde_linear_fmt_map + (_QWORD)v5 + 4) == (_DWORD)v4 )
      break;
    v5 += 2;
    if ( v5 == qword_2E0 )
      goto LABEL_53;
  }
  v7 = 736;
LABEL_51:
  if ( v7 > (unsigned __int64)v5 )
  {
    result = *v6;
    if ( (_DWORD)result != -1 )
      return result;
    goto LABEL_53;
  }
  __break(1u);
  return sde_connector_add_roi_v1(a1, a2, a3, v4);
}
