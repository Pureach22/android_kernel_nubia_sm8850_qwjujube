__int64 __fastcall zte_set_disp_parameter(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x8
  int v6; // w21
  __int64 v7; // x23
  __int64 v8; // x8
  __int64 v9; // x9
  __int64 v10; // x24
  __int64 v11; // x8
  __int64 v12; // x1
  unsigned int v13; // w22
  __int64 v14; // x8
  int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x1

  if ( !a1 )
  {
    printk(&unk_241376, a2);
    return (unsigned int)-22;
  }
  v3 = *(_QWORD *)(a1 + 1424);
  v6 = a2;
  if ( v3 )
    v7 = *(_QWORD *)(v3 + 184);
  else
    v7 = 0;
  v8 = *(_QWORD *)(a1 + 2312);
  v9 = v8 + 16LL * (unsigned int)a2;
  if ( (*(_BYTE *)(v9 + 12) & 1) == 0 )
  {
    printk(&unk_24AFD3, *(_QWORD *)v9);
    return 0;
  }
  v10 = (unsigned int)a2;
  if ( (*(_BYTE *)(v9 + 13) & 1) == 0 )
  {
    *(_DWORD *)(v9 + 8) = a3;
    v8 = *(_QWORD *)(a1 + 2312);
  }
  v11 = v8 + 16LL * (unsigned int)a2;
  if ( *(_BYTE *)(v11 + 14) == 1 )
    printk(&unk_251E48, *(_QWORD *)v11);
  mutex_lock(a1 + 1040);
  if ( (*(_BYTE *)(a1 + 1973) & 1) == 0 )
  {
    printk(&unk_260943, v12);
    v13 = 0;
    goto LABEL_31;
  }
  v13 = 0;
  if ( v6 <= 7 )
  {
    if ( v6 == 3 )
    {
      v17 = a3 + 46;
    }
    else
    {
      if ( v6 != 4 )
      {
        if ( v6 == 7 )
        {
          if ( *(_DWORD *)(*(_QWORD *)(a1 + 2312) + 16 * v10 + 8) == a3 )
          {
            v13 = 0;
          }
          else
          {
            v13 = zte_dsi_panel_tx_cmd_set(a1, a3 + 50);
            *(_DWORD *)(*(_QWORD *)(a1 + 2312) + 120LL) = a3;
          }
        }
        goto LABEL_31;
      }
      v17 = a3 + 42;
    }
    goto LABEL_30;
  }
  if ( (unsigned int)(v6 - 8) < 2 )
  {
    if ( v7 )
    {
      v14 = *(_QWORD *)(v7 + 2176);
      if ( v14 )
      {
        v15 = *(_DWORD *)(v7 + 2168);
        if ( v15 )
        {
          v16 = *(_QWORD *)(v14 + ((unsigned __int64)(unsigned int)(v15 - 1) << 6) + 16);
          if ( v16 )
          {
            if ( *(_BYTE *)v16 == 81 )
            {
              *(_WORD *)(v16 + 1) = bswap32(a3) >> 16;
              if ( v6 == 8 )
                printk(&unk_24E5B7, 81);
            }
          }
        }
      }
    }
    *(_BYTE *)(v7 + 2192) = v6 == 8;
    v13 = zte_dsi_panel_tx_cmd_set(a1, 54);
    *(_BYTE *)(a1 + 2558) = 1;
    goto LABEL_31;
  }
  if ( v6 == 13 )
  {
    v17 = a3 + 57;
LABEL_30:
    v13 = zte_dsi_panel_tx_cmd_set(a1, v17);
  }
LABEL_31:
  mutex_unlock(a1 + 1040);
  return v13;
}
