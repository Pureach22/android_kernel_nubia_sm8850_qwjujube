__int64 __fastcall get_hfi_buffer(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x4
  int v4; // w8
  int v5; // w8
  __int64 v6; // x8
  int v7; // w8
  int v8; // w8
  int v9; // w9
  int v10; // w8
  __int64 v12; // x19
  __int64 v13; // x20
  __int64 v14; // x21

  *(_QWORD *)(a3 + 48) = 0;
  *(_QWORD *)(a3 + 56) = 0;
  *(_QWORD *)(a3 + 32) = 0;
  *(_QWORD *)(a3 + 40) = 0;
  *(_QWORD *)(a3 + 16) = 0;
  *(_QWORD *)(a3 + 24) = 0;
  *(_QWORD *)a3 = 0;
  *(_QWORD *)(a3 + 8) = 0;
  v3 = *(unsigned int *)(a2 + 24);
  if ( (int)v3 > 9 )
  {
    if ( (int)v3 <= 12 )
    {
      if ( (_DWORD)v3 == 10 )
      {
        v5 = 11;
      }
      else if ( (_DWORD)v3 == 11 )
      {
        v5 = 8;
      }
      else
      {
        v5 = 6;
      }
      goto LABEL_33;
    }
    switch ( (_DWORD)v3 )
    {
      case 0xD:
        v5 = 12;
        goto LABEL_33;
      case 0xE:
        v5 = 13;
        goto LABEL_33;
      case 0xF:
        v5 = 5;
        goto LABEL_33;
    }
  }
  else
  {
    if ( (int)v3 > 6 )
    {
      if ( (_DWORD)v3 == 7 )
      {
        v5 = 7;
      }
      else if ( (_DWORD)v3 == 8 )
      {
        v5 = 9;
      }
      else
      {
        v5 = 10;
      }
      goto LABEL_33;
    }
    if ( (unsigned int)(v3 - 3) < 2 )
    {
      v5 = 3;
      goto LABEL_33;
    }
    v4 = *(_DWORD *)(a1 + 308);
    if ( (_DWORD)v3 == 1 )
    {
      if ( v4 == 2 )
        v5 = 1;
      else
        v5 = 2;
      goto LABEL_33;
    }
    if ( (_DWORD)v3 == 2 )
    {
      if ( v4 == 2 )
        v5 = 2;
      else
        v5 = 1;
      goto LABEL_33;
    }
  }
  if ( (msm_vidc_debug & 1) != 0 )
  {
    v12 = a1;
    v13 = a2;
    v14 = a3;
    printk(&unk_94430, "err ", 0xFFFFFFFFLL, "codec", v3);
    a1 = v12;
    a2 = v13;
    a3 = v14;
  }
  v5 = 0;
LABEL_33:
  *(_DWORD *)a3 = v5;
  *(_DWORD *)(a3 + 4) = *(_DWORD *)(a2 + 32);
  v6 = *(_QWORD *)(a2 + 56);
  *(_DWORD *)(a3 + 16) = 0;
  *(_QWORD *)(a3 + 8) = v6;
  v7 = *(_DWORD *)(a2 + 40);
  *(_DWORD *)(a3 + 20) = v7;
  if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)(a2 + 24) == 1 )
    *(_DWORD *)(a3 + 20) = (v7 + 255) & 0xFFFFFF00;
  *(_DWORD *)(a3 + 24) = *(_DWORD *)(a2 + 44);
  *(_DWORD *)(a3 + 28) = *(_DWORD *)(a2 + 48);
  v8 = *(_DWORD *)(a2 + 80);
  if ( (v8 & 2) != 0 )
  {
    *(_DWORD *)(a3 + 40) |= 0x10u;
    if ( (*(_DWORD *)(a2 + 80) & 4) == 0 )
    {
LABEL_38:
      if ( (*(_BYTE *)(a2 + 67) & 1) == 0 )
        goto LABEL_40;
      goto LABEL_39;
    }
  }
  else if ( (v8 & 4) == 0 )
  {
    goto LABEL_38;
  }
  *(_DWORD *)(a3 + 40) |= 1u;
  if ( (*(_BYTE *)(a2 + 67) & 1) != 0 )
LABEL_39:
    *(_DWORD *)(a3 + 40) |= 0x100u;
LABEL_40:
  v9 = *(_DWORD *)(a2 + 28);
  if ( v9 > 15 )
  {
    switch ( v9 )
    {
      case 16:
        v10 = 4096;
        goto LABEL_55;
      case 32:
        v10 = 2048;
        goto LABEL_55;
      case 64:
        v10 = 1024;
        goto LABEL_55;
    }
    goto LABEL_53;
  }
  v10 = 512;
  if ( v9 != 2 && v9 != 4 )
  {
    if ( v9 == 8 )
    {
      v10 = 0x2000;
      goto LABEL_55;
    }
LABEL_53:
    v10 = 0;
  }
LABEL_55:
  *(_DWORD *)(a3 + 40) |= v10;
  *(_QWORD *)(a3 + 32) = *(_QWORD *)(a2 + 72);
  return 0;
}
