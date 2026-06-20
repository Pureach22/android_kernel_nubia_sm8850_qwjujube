__int64 __fastcall populate_dot11f_mlo_caps(__int64 a1, __int64 a2, __int16 *a3)
{
  __int16 v6; // w9
  __int16 v7; // w9
  char v8; // w21
  __int16 v9; // w8
  __int64 v10; // x10
  _DWORD *v11; // x11
  unsigned int v12; // w12
  _DWORD *v13; // x10
  unsigned int v14; // w11
  __int16 v16; // w9

  *a3 &= 0xFFF8u;
  qdf_mem_copy((char *)a3 + 3, (const void *)(*(_QWORD *)(a2 + 16) + 80LL), 6u);
  v6 = *a3;
  *a3 &= 0xFF8Fu;
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 49LL) & 4) != 0 )
  {
    v8 = 11;
    v7 = v6 & 0xFF0F | 0x80;
    a3[7] = a3[7] & 0xFF7E | 1;
  }
  else
  {
    v7 = v6 & 0xFF0F;
    v8 = 9;
  }
  v9 = v7 & 0xFBFF;
  *a3 = v7 & 0xFBFF;
  v10 = *(_QWORD *)(a1 + 21624);
  if ( v10 )
  {
    v11 = *(_DWORD **)(v10 + 2800);
    if ( v11 )
    {
      v12 = v11[126];
      v13 = v11 + 780;
      if ( v12 <= 0xA )
      {
        if ( *v13 == v12 )
        {
          v14 = 0;
        }
        else if ( v11[826] == v12 )
        {
          v14 = 1;
        }
        else if ( v11[872] == v12 )
        {
          v14 = 2;
        }
        else if ( v11[918] == v12 )
        {
          v14 = 3;
        }
        else if ( v11[964] == v12 )
        {
          v14 = 4;
        }
        else if ( v11[1010] == v12 )
        {
          v14 = 5;
        }
        else if ( v11[1056] == v12 )
        {
          v14 = 6;
        }
        else
        {
          if ( v11[1102] != v12 )
            goto LABEL_27;
          v14 = 7;
        }
        v13 += 46 * v14;
      }
      if ( v13 && (v13[45] & 0x80) != 0 )
      {
        v8 += 2;
        v9 = v7 | 0x400;
        a3[10] |= 0x80u;
      }
    }
  }
LABEL_27:
  *a3 = v9 & 0xFCFF | 0x100;
  v16 = a3[8] & 0xDF9F | (32 * (wlan_mlme_get_t2lm_negotiation_supported(*(_QWORD *)(a1 + 21624)) & 3));
  *a3 &= 0xFF7u;
  a3[8] = v16;
  *((_BYTE *)a3 + 2) = v8;
  return 0;
}
