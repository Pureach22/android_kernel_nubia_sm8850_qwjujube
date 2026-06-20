__int64 __fastcall cam_isp_hw_mgr_add_cmd_buf_util(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        unsigned int a6)
{
  __int64 v6; // x19
  unsigned int v7; // w7
  unsigned int v8; // w10
  unsigned int *v9; // x12
  unsigned int v10; // w8
  __int64 v11; // x6
  __int64 v12; // x9
  __int64 result; // x0
  unsigned __int64 v14; // x9
  __int64 **v15; // x13
  __int64 v16; // x12
  __int64 v19; // x1
  char v20; // w4
  int v21; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+18h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a3 + 16);
  v21 = 0;
  v8 = *(_DWORD *)(v6 + 20);
  v7 = *(_DWORD *)(v6 + 24);
  if ( v8 <= v7 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_hw_mgr_add_cmd_buf_util",
      11930,
      "No free kmd memory for base idx: %d used_bytes %u buf_size %u",
      **(unsigned int **)(a3 + 8));
    result = 4294967284LL;
LABEL_18:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v9 = *(unsigned int **)(a3 + 8);
  v10 = v9[2];
  v11 = *v9;
  if ( v10 != 7 )
  {
    if ( v10 != 2 )
    {
      if ( v10 )
        goto LABEL_16;
      if ( (unsigned int)v11 < 8 )
      {
        v12 = g_ife_hw_mgr[v11 + 12];
        if ( !v12 )
          goto LABEL_16;
LABEL_15:
        v16 = v9[1];
        if ( (unsigned int)v16 < 2 )
        {
          result = *(_QWORD *)(a1 + 8 * v16 + 32);
          if ( !result )
            goto LABEL_18;
          if ( !(unsigned int)cam_isp_add_cmd_buf_update(
                                result,
                                v12,
                                a6,
                                a5,
                                (const void *)(*(_QWORD *)(v6 + 8) + (v7 & 0xFFFFFFFC)),
                                v8 - v7,
                                a4,
                                &v21) )
          {
            if ( v21 )
            {
              if ( *(_BYTE *)(a3 + 24) == 1 )
              {
                v19 = a2;
                v20 = *(_DWORD *)(*(_QWORD *)(a2 + 32) + 32LL * (unsigned int)(*(_DWORD *)(a2 + 40) - 1) + 12) == 2;
              }
              else
              {
                v20 = 0;
                v19 = a2;
              }
              cam_isp_update_hw_entry(2, v19, v6, v21, v20);
              result = 0;
              *(_BYTE *)(a3 + 24) = 1;
            }
            else
            {
              result = 0;
            }
            goto LABEL_18;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_isp_hw_mgr_add_cmd_buf_util",
            11954,
            "Add cmd buffer failed idx: %d",
            **(_DWORD **)(a3 + 8));
          goto LABEL_17;
        }
LABEL_16:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_hw_mgr_add_cmd_buf_util",
          11940,
          "Invalid base %u type %u",
          v11,
          v10);
LABEL_17:
        result = 4294967274LL;
        goto LABEL_18;
      }
      goto LABEL_28;
    }
    if ( (unsigned int)v11 <= 7 )
    {
      v14 = 8 * v11 + 160;
      v15 = (__int64 **)((char *)g_ife_hw_mgr + v14);
      goto LABEL_13;
    }
LABEL_28:
    __break(0x5512u);
    goto LABEL_29;
  }
  if ( (unsigned int)v11 > 2 )
    goto LABEL_28;
  v14 = (8 * v11) | 0xE0;
  v15 = (__int64 **)&g_ife_hw_mgr[v11 + 28];
LABEL_13:
  if ( v14 <= 0x13FD8 )
  {
    v12 = **v15;
    if ( !v12 )
      goto LABEL_16;
    goto LABEL_15;
  }
LABEL_29:
  __break(1u);
  return cam_isp_blob_csid_irq_comp_cfg(a1, a2, a3, a4);
}
