__int64 __fastcall get_irq_bit_0(__int64 a1, __int64 a2)
{
  unsigned int v3; // w8

  if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
  {
    if ( a2 && (*(_BYTE *)(a2 + 203) & 0x20) != 0 )
    {
      return 4;
    }
    else
    {
      v3 = *(_DWORD *)(a2 + 8) >> 2;
      if ( v3 >= 3 )
        return 3;
      else
        return v3;
    }
  }
  else if ( a2 )
  {
    return (*(_DWORD *)(a2 + 200) >> 29) & 1;
  }
  else
  {
    return 0;
  }
}
