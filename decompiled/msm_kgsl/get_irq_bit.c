__int64 __fastcall get_irq_bit(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned int v6; // w8

  if ( (adreno_hwsched_context_queue_enabled(a1) & 1) == 0 )
    return *(unsigned int *)(*(_QWORD *)(a2 + 8) + 292LL);
  v4 = *(_QWORD *)(a2 + 8);
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) != 0 )
  {
    if ( v4 && (*(_BYTE *)(v4 + 203) & 0x20) != 0 )
    {
      return 4;
    }
    else
    {
      v6 = *(_DWORD *)(v4 + 8) >> 2;
      if ( v6 >= 3 )
        return 3;
      else
        return v6;
    }
  }
  else if ( v4 )
  {
    return (*(_DWORD *)(v4 + 200) >> 29) & 1;
  }
  else
  {
    return 0;
  }
}
