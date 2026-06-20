__int64 __fastcall mdt_load_split_segment(__int64 a1, __int64 a2, unsigned int a3, char *s, __int64 a5)
{
  __int64 result; // x0
  __int64 v11; // x0
  const char *v12; // x19
  size_t v13; // x0
  __int64 v14; // x23
  _DWORD *v15; // x23
  unsigned int v16; // t1
  int v17; // w0
  __int64 v18; // x20
  __int64 v19; // x2
  __int64 v20; // x0
  _QWORD v21[2]; // [xsp+0h] [xbp-10h] BYREF

  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21[0] = 0;
  if ( strlen(s) >= 4 )
  {
    v11 = kstrdup(s, 3264);
    if ( !v11 )
    {
      result = -12;
      goto LABEL_11;
    }
    v12 = (const char *)v11;
    v13 = strlen(s);
    sprintf((char *)&v12[v13 - 3], "b%02d", a3);
    v14 = a2 + 32LL * a3;
    v16 = *(_DWORD *)(v14 + 16);
    v15 = (_DWORD *)(v14 + 16);
    v17 = request_firmware_into_buf(v21, v12, a5, a1, v16);
    if ( v17 )
    {
      v19 = v17;
      v20 = a5;
      v18 = v19;
      dev_err(v20, "error %zd loading %s\n", v19, v12);
      if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_9;
    }
    else
    {
      if ( *(_QWORD *)v21[0] == *v15 )
      {
        v18 = 0;
      }
      else
      {
        dev_err(a5, "failed to load segment %d from truncated file %s\n", a3, v12);
        v18 = -22;
      }
      release_firmware();
      if ( (unsigned __int64)v12 > 0xFFFFFFFFFFFFF000LL )
        goto LABEL_9;
    }
    kfree(v12);
LABEL_9:
    result = v18;
    goto LABEL_11;
  }
  result = -22;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
