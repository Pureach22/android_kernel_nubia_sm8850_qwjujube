__int64 __fastcall coresight_alloc_device_name(unsigned int *a1, __int64 a2)
{
  __int64 device_name; // x21
  __int64 v5; // x0
  __int64 v6; // x23
  __int64 v7; // x4
  unsigned __int64 v8; // x21
  unsigned __int64 v9; // x22
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x24
  __int64 v13; // x25

  mutex_lock(&coresight_mutex);
  device_name = coresight_get_device_name(a2);
  if ( !device_name )
  {
    v5 = _dev_fwnode(a2);
    v6 = *a1;
    if ( (int)v6 < 1 )
      goto LABEL_8;
    v7 = 0;
    while ( *(_QWORD *)(*((_QWORD *)a1 + 2) + 8 * v7) != v5 )
    {
      if ( v6 == ++v7 )
        goto LABEL_8;
    }
    if ( (v7 & 0x80000000) != 0 )
    {
LABEL_8:
      if ( (int)v6 + 1 >= 0 )
      {
        v8 = 8LL * (unsigned int)(v6 + 1);
        v9 = krealloc_noprof(*((_QWORD *)a1 + 2), v8, 3264);
        while ( v9 >= 0x11 )
        {
          v10 = _dev_fwnode(a2);
          if ( v8 >= 8LL * (int)v6 && v8 - 8LL * (int)v6 >= 8 )
          {
            LODWORD(v7) = v6;
            *(_QWORD *)(v9 + 8LL * (int)v6) = v10;
            *((_QWORD *)a1 + 2) = v9;
            *a1 = v6 + 1;
            goto LABEL_15;
          }
          __break(1u);
          StatusReg = _ReadStatusReg(SP_EL0);
          v13 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &coresight_alloc_device_name__alloc_tag;
          if ( (int)v6 + 1 < 0 )
          {
            v8 = 0;
            v9 = 0;
          }
          else
          {
            v8 = 8LL * (unsigned int)(v6 + 1);
            v9 = krealloc_noprof(*((_QWORD *)a1 + 2), v8, 3264);
          }
          *(_QWORD *)(StatusReg + 80) = v13;
        }
      }
      device_name = 0;
    }
    else
    {
LABEL_15:
      device_name = devm_kasprintf(a2, 3264, "%s%d", *((const char **)a1 + 1), v7);
    }
  }
  mutex_unlock(&coresight_mutex);
  return device_name;
}
