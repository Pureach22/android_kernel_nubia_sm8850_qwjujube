__int64 __fastcall tmc_read_unprepare_etr(__int64 a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  void (__fastcall *v4)(_QWORD); // x8

  if ( *(_DWORD *)(a1 + 140) == 1 )
  {
    mutex_lock(a1 + 152);
    raw_spin_lock_irqsave(a1 + 104);
    if ( (unsigned int)*(_QWORD *)(*(_QWORD *)(a1 + 16) + 968LL) == 1 )
    {
      _tmc_etr_enable_hw(a1);
      *(_BYTE *)(a1 + 112) = 0;
      raw_spin_unlock_irqrestore(a1 + 104);
    }
    else
    {
      v2 = *(_QWORD *)(a1 + 288);
      *(_QWORD *)(a1 + 288) = 0;
      *(_BYTE *)(a1 + 112) = 0;
      raw_spin_unlock_irqrestore(a1 + 104);
      if ( v2 )
      {
        v3 = *(_QWORD *)(v2 + 48);
        if ( !v3 || (v4 = *(void (__fastcall **)(_QWORD))(v3 + 24)) == nullptr )
        {
          __break(0x800u);
          v4 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v2 + 48) + 24LL);
        }
        if ( *((_DWORD *)v4 - 1) != 1050944703 )
          __break(0x8228u);
        v4(v2);
        kfree(v2);
      }
    }
    mutex_unlock(a1 + 152);
    return 0;
  }
  else
  {
    __break(0x800u);
    return 4294967274LL;
  }
}
