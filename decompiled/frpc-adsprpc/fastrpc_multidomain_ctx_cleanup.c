__int64 __fastcall fastrpc_multidomain_ctx_cleanup(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x23
  __int64 v7; // x0
  _QWORD *v8; // x19
  unsigned int v9; // w21
  _QWORD *v10; // x8
  __int64 v11; // x9

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 128) + 168LL);
  mutex_lock(&unk_26CA8);
  v7 = idr_find(&qword_27518, (int)a3);
  if ( v7 && (v8 = (_QWORD *)v7, *(_QWORD *)(v7 + 72) == a3) && *(_QWORD *)(v7 + 64) == a1 )
  {
    v9 = fastrpc_multidomain_ctx_dsp_manage(a1, a2, a3, v7, *(unsigned int *)(v7 + 56));
    if ( v9 )
      dev_err(v5, "Error 0x%x: %s: peer-info deregister failed for ctx 0x%x", v9, "fastrpc_multidomain_ctx_cleanup", a3);
    idr_remove(&qword_27518, (int)a3);
    raw_spin_lock(a1 + 320);
    v10 = (_QWORD *)v8[1];
    if ( (_QWORD *)*v10 == v8 && (v11 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
    {
      *(_QWORD *)(v11 + 8) = v10;
      *v10 = v11;
    }
    else
    {
      _list_del_entry_valid_or_report(v8);
    }
    *v8 = 0xDEAD000000000100LL;
    v8[1] = 0xDEAD000000000122LL;
    raw_spin_unlock(a1 + 320);
    kfree(v8[6]);
    kfree(v8[5]);
    kfree(v8[2]);
    kfree(v8);
  }
  else
  {
    v9 = -13;
    dev_err(
      v5,
      "Error %d: %s: attempting to remove ctx 0x%x of another app",
      -13,
      "fastrpc_multidomain_ctx_cleanup",
      a3);
  }
  mutex_unlock(&unk_26CA8);
  return v9;
}
