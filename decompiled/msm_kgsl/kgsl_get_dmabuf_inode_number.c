__int64 __fastcall kgsl_get_dmabuf_inode_number(__int64 a1)
{
  __int64 v1; // x8

  v1 = *(_QWORD *)(a1 + 216);
  if ( v1 )
    return *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 16) + 8LL) + 40LL) + 64LL);
  else
    return 0;
}
