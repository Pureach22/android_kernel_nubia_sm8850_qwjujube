__int64 __fastcall gpi_issue_pending(__int64 a1)
{
  __int64 v1; // x22
  __int64 lock_irqsave; // x19
  __int64 v4; // x1
  __int64 v5; // x10
  _QWORD *v6; // x8
  _QWORD *v7; // x11
  _QWORD *v8; // x12
  __int64 v9; // x21
  __int64 v10; // x8
  __int64 v11; // x10
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x21

  v1 = *(_QWORD *)(a1 + 280);
  lock_irqsave = raw_read_lock_irqsave(v1 + 948);
  v4 = raw_spin_lock_irqsave(a1 + 160);
  v5 = *(_QWORD *)(a1 + 184);
  v6 = (_QWORD *)(a1 + 200);
  if ( v5 != a1 + 184 )
  {
    v7 = *(_QWORD **)(a1 + 208);
    v8 = *(_QWORD **)(a1 + 192);
    *(_QWORD *)(v5 + 8) = v7;
    *v7 = v5;
    *v8 = v6;
    *(_QWORD *)(a1 + 208) = v8;
    *(_QWORD *)(a1 + 184) = a1 + 184;
    *(_QWORD *)(a1 + 192) = a1 + 184;
  }
  if ( (_QWORD *)*v6 == v6 )
  {
    raw_spin_unlock_irqrestore(a1 + 160, v4);
  }
  else
  {
    v9 = *(_QWORD *)(a1 + 208);
    raw_spin_unlock_irqrestore(a1 + 160, v4);
    if ( v9 != 152 )
    {
      v10 = *(_QWORD *)(a1 + 352);
      v11 = *(_QWORD *)(v10 + 16);
      v12 = *(_QWORD *)(v10 + 32);
      v13 = v11 + *(_QWORD *)(v9 + 24);
      v14 = v13 - v12;
      writel_relaxed(v13 - v12, *(unsigned int **)(a1 + 304));
      writel_relaxed(HIDWORD(v14), (unsigned int *)(*(_QWORD *)(a1 + 304) + 4LL));
    }
  }
  return raw_read_unlock_irqrestore(v1 + 948, lock_irqsave);
}
