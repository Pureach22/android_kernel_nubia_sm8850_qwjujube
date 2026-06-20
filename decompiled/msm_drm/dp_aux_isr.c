__int64 __fastcall dp_aux_isr(__int64 a1)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  __int64 v4; // x0
  int v5; // w8
  void (*v6)(void); // x8

  if ( !a1 )
  {
    _ReadStatusReg(SP_EL0);
    return printk(&unk_275B6D, "dp_aux_isr");
  }
  v2 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 120) + 72LL);
  if ( *((_DWORD *)v2 - 1) != 497885965 )
    __break(0x8228u);
  result = v2();
  if ( *(_BYTE *)(a1 + 1802) == 1 )
  {
    v4 = *(_QWORD *)(a1 + 120);
    v5 = *(_DWORD *)(v4 + 4);
    if ( *(_BYTE *)(a1 + 1803) == 1 )
    {
      if ( (v5 & 8) != 0 )
      {
        *(_DWORD *)(a1 + 1816) = 0;
        if ( (v5 & 0x1000) == 0 )
          goto LABEL_34;
      }
      else if ( (v5 & 0x40) != 0 )
      {
        *(_DWORD *)(a1 + 1816) = -1;
        if ( (v5 & 0x1000) == 0 )
          goto LABEL_34;
      }
      else if ( (v5 & 0x200) != 0 )
      {
        *(_DWORD *)(a1 + 1816) = -2;
        if ( (v5 & 0x1000) == 0 )
          goto LABEL_34;
      }
      else if ( (v5 & 0x1000) == 0 )
      {
LABEL_34:
        if ( (v5 & 0x8000000) != 0 )
        {
LABEL_35:
          *(_DWORD *)(a1 + 1816) = -6;
          v6 = *(void (**)(void))(v4 + 80);
          if ( *((_DWORD *)v6 - 1) != -1040530234 )
            __break(0x8228u);
          v6();
        }
        return complete(a1 + 192);
      }
      *(_DWORD *)(a1 + 1816) = -3;
      if ( (v5 & 0x8000000) != 0 )
        goto LABEL_35;
      return complete(a1 + 192);
    }
    if ( (v5 & 8) != 0 )
    {
      if ( (*(_DWORD *)(v4 + 4) & 0x240000) != 0 )
        *(_DWORD *)(a1 + 1816) = -3;
      else
        *(_DWORD *)(a1 + 1816) = 0;
      return complete(a1 + 192);
    }
    if ( (v5 & 0x40) != 0 )
    {
      *(_DWORD *)(a1 + 1816) = -1;
      if ( (v5 & 0x1000) != 0 )
        goto LABEL_32;
    }
    else
    {
      if ( (v5 & 0x200) == 0 )
      {
        if ( (v5 & 0x1000) == 0 )
          goto LABEL_15;
LABEL_32:
        *(_DWORD *)(a1 + 1816) = -5;
        if ( (v5 & 0x40000) == 0 )
        {
LABEL_16:
          if ( (v5 & 0x200000) == 0 )
            goto LABEL_34;
          goto LABEL_40;
        }
LABEL_33:
        *(_DWORD *)(a1 + 1816) = -3;
        if ( (v5 & 0x200000) == 0 )
          goto LABEL_34;
LABEL_40:
        *(_DWORD *)(a1 + 1816) = -4;
        if ( (v5 & 0x8000000) != 0 )
          goto LABEL_35;
        return complete(a1 + 192);
      }
      *(_DWORD *)(a1 + 1816) = -2;
      if ( (v5 & 0x1000) != 0 )
        goto LABEL_32;
    }
LABEL_15:
    if ( (v5 & 0x40000) == 0 )
      goto LABEL_16;
    goto LABEL_33;
  }
  return result;
}
