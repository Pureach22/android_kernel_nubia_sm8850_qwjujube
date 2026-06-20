__int64 __fastcall task_rq_unlock(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_DWORD *)(a1 + 3392) >= 3u )
    *(_DWORD *)(a3 + 8) = 4;
  raw_spin_rq_unlock(a1);
  return raw_spin_unlock_irqrestore(a2 + 2540, *(_QWORD *)a3);
}
