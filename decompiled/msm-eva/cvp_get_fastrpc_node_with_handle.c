__int64 *__fastcall cvp_get_fastrpc_node_with_handle(unsigned int a1)
{
  __int64 v2; // x3
  __int64 *v3; // x21
  __int64 *v4; // x20
  unsigned int v12; // w9

  mutex_lock(&unk_6CF58);
  v3 = &qword_6CF48;
  while ( 1 )
  {
    v3 = (__int64 *)*v3;
    v4 = nullptr;
    if ( v3 == &qword_6CF48 || !v3 )
      break;
    if ( *((_DWORD *)v3 + 4) == a1 )
    {
      _X8 = (unsigned int *)v3 + 7;
      __asm { PRFM            #0x11, [X8] }
      do
        v12 = __ldxr(_X8);
      while ( __stxr(v12 + 1, _X8) );
      if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
        printk(&unk_85C78, "dsp", a1, v2);
      v4 = v3;
      break;
    }
  }
  mutex_unlock(&unk_6CF58);
  if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    printk(&unk_852D9, "dsp", "cvp_get_fastrpc_node_with_handle", v4);
  return v4;
}
