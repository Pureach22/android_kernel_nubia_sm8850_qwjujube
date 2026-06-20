__int64 __fastcall _fence_state(unsigned __int64 a1, char a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  __int64 (*v6)(void); // x8
  unsigned __int64 v7; // x19
  unsigned int status; // w0
  unsigned int v10; // w8

  if ( a1 && a1 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( (a2 & 1) != 0 )
    {
      if ( (*(_QWORD *)(a1 + 48) & 1) == 0 )
      {
        v6 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 8) + 32LL);
        if ( !v6 )
          return 1;
        v7 = a1;
        if ( *((_DWORD *)v6 - 1) != 1879296680 )
          __break(0x8228u);
        if ( (v6() & 1) == 0 )
          return 1;
        dma_fence_signal_locked(v7);
        a1 = v7;
      }
      if ( *(_DWORD *)(a1 + 60) <= 1u )
        status = 1;
      else
        status = *(_DWORD *)(a1 + 60);
    }
    else
    {
      status = dma_fence_get_status();
    }
    v10 = status + 6;
    if ( status + 6 < 8 && ((0xCDu >> v10) & 1) != 0 )
    {
      return dword_2BF20[v10];
    }
    else if ( status <= 0xFFFFFFBF )
    {
      return -status;
    }
    else
    {
      return 5;
    }
  }
  else
  {
    if ( (synx_debug & 1) != 0 )
      printk(&unk_289DC, &unk_29207, "__fence_state", 846, a5, a6);
    return 0;
  }
}
