__int64 init_module()
{
  __int64 v0; // x8
  _QWORD *v1; // x9
  __int64 v2; // x19
  unsigned __int64 *v3; // x23
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x20
  unsigned __int64 v6; // x19

  v0 = 0;
  v1 = gh_hvc_data;
  do
  {
    *((_DWORD *)v1 + 2) = v0++;
    v1[4] = v1 + 5;
    v1[135] = v1 + 136;
    v1[2] = 0;
    v1[3] = 0x1000003FFLL;
    v1[133] = 0;
    v1[134] = 0x1000003FFLL;
    v1[264] = 0xFFFFFFFE00000LL;
    v1[265] = v1 + 265;
    v1[266] = v1 + 265;
    v1[267] = gh_hvc_put_work_fn;
    v1 += 268;
  }
  while ( v0 != 5 );
  ((void (*)(void))hvc_gh_console_init)();
  v2 = 0;
  v3 = gh_hvc_data;
  do
  {
    v4 = hvc_alloc((unsigned int)(v2 + 1196317000), (unsigned int)v2, gh_hv_ops, 256);
    *v3 = v4;
    if ( v4 >= 0xFFFFFFFFFFFFF001LL )
    {
      if ( (int)v2 >= 1 )
        goto LABEL_11;
      return 0;
    }
    ++v2;
    v3 += 268;
  }
  while ( v2 != 5 );
  v4 = gh_rm_register_notifier(&gh_hvc_nb);
  if ( (_DWORD)v4 )
    goto LABEL_9;
  if ( !(unsigned int)gunyah_qtvm_register_notifier(&gh_hvc_vm_nb) )
    return 0;
  v4 = gh_rm_unregister_notifier(&gh_hvc_nb);
LABEL_9:
  v2 = 5;
LABEL_11:
  v5 = 2144 * v2 - 2144;
  v6 = v2 + 1;
  while ( v5 >> 5 <= 0x14E )
  {
    v4 = hvc_remove(*(_QWORD *)((char *)gh_hvc_data + v5));
    --v6;
    *(_QWORD *)((char *)gh_hvc_data + v5) = 0;
    v5 -= 2144LL;
    if ( v6 <= 1 )
      return 0;
  }
  __break(1u);
  return hvc_gh_console_init(v4);
}
