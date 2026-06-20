__int64 __fastcall kgsl_get_egl_counts(__int64 result, _DWORD *a2, _DWORD *a3)
{
  __int64 v3; // x21
  _QWORD *i; // x8
  _QWORD *v7; // x21
  _QWORD *v8; // t1
  int v9; // w10
  _DWORD *v10; // x9

  v3 = *(_QWORD *)(*(_QWORD *)(result + 216) + 32LL);
  if ( v3 )
  {
    raw_spin_lock(&kgsl_dmabuf_lock);
    v8 = *(_QWORD **)(v3 + 24);
    v7 = (_QWORD *)(v3 + 24);
    for ( i = v8; ; i = (_QWORD *)*i )
    {
      if ( i == v7 )
        return raw_spin_unlock(&kgsl_dmabuf_lock);
      v9 = *(unsigned __int8 *)(*(i - 5) + 81LL);
      v10 = a2;
      if ( (unsigned int)(v9 - 7) < 2 )
        goto LABEL_3;
      if ( v9 == 18 )
        break;
LABEL_4:
      ;
    }
    v10 = a3;
LABEL_3:
    ++*v10;
    goto LABEL_4;
  }
  return result;
}
