__int64 __fastcall mem_object_release(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a1 )
    return cbo_release();
  else
    return printk(&unk_104DD, "mem_object_release", a3);
}
