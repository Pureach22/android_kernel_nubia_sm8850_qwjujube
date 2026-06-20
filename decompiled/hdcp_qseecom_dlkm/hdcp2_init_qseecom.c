_QWORD *__fastcall hdcp2_init_qseecom(int a1)
{
  __int64 v2; // x0
  _QWORD *v3; // x19
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8

  v2 = _kmalloc_cache_noprof(qseecom_send_command, 3520, 136);
  v3 = (_QWORD *)v2;
  if ( v2 )
  {
    *(_DWORD *)(v2 + 80) = a1;
    *(_QWORD *)(v2 + 88) = "hdcp2p2";
    v4 = _kmalloc_cache_noprof(_stack_chk_fail, 3264, 4096);
    v3[13] = v4;
    if ( v4 )
    {
      v5 = _kmalloc_cache_noprof(_stack_chk_fail, 3264, 4096);
      v3[12] = v5;
      if ( v5 )
      {
        v6 = v3[13];
        v3[1] = v5;
        v3[3] = v6;
        return v3;
      }
      kfree_sensitive(v3[13]);
    }
    kfree_sensitive(v3);
    return nullptr;
  }
  return v3;
}
