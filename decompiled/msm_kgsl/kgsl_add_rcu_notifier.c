__int64 __fastcall kgsl_add_rcu_notifier(__int64 a1)
{
  char *v2; // x20

  mutex_lock(&unk_3A878);
  v2 = (char *)off_3A7F8;
  if ( off_3A7F8 && !*(int *)((char *)&dword_10 + (_QWORD)off_3A7F8) )
  {
    mutex_unlock(&unk_3A878);
    return srcu_notifier_chain_register(v2 + 13424, a1);
  }
  else
  {
    mutex_unlock(&unk_3A878);
    return 4294967277LL;
  }
}
