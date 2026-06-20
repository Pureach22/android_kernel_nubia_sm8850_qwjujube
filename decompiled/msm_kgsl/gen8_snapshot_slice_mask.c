__int64 __fastcall gen8_snapshot_slice_mask(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  int v5; // w8

  if ( a3 > 0xB )
  {
    *(_QWORD *)a2 = 0x100000020LL;
    v5 = *(_DWORD *)(a1 + 24612);
    *(_DWORD *)(a2 + 8) = v5;
    return 12;
  }
  else
  {
    if ( (unsigned int)__ratelimit(&gen8_snapshot_slice_mask__rs, "gen8_snapshot_slice_mask") )
      dev_err(*(_QWORD *)a1, "snapshot: not enough snapshot memory for section %s\n", "SLICE MASK DEBUG");
    return 0;
  }
}
