__int64 __fastcall cali_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x21
  int v6; // w0
  __int64 *v7; // x8
  __int64 v8; // x1

  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 152) + 96LL);
  v6 = ((__int64 (__fastcall *)(__int64, __int64))aw_cali_svc_get_cmd_form_str)(v5, a3);
  if ( v6 < 0 )
    goto LABEL_9;
  if ( v6 == 3 )
  {
    aw_cali_svc_cali_f0(v5, 0, 2);
    return a4;
  }
  if ( v6 == 2 )
  {
    aw_cali_svc_cali_re(v5, 0, 1);
    return a4;
  }
  if ( v6 != 1 )
  {
LABEL_9:
    v7 = *(__int64 **)(v5 + 112);
    v8 = v7[14];
    if ( !v8 )
      v8 = *v7;
    printk(&unk_24E97, v8, "cali_store");
    return -1;
  }
  else if ( !(unsigned int)aw_cali_svc_cali_re(v5, 0, 3) )
  {
    aw_cali_svc_cali_f0(v5, 0, 3);
  }
  return a4;
}
