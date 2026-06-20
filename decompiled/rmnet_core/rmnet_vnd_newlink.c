__int64 __fastcall rmnet_vnd_newlink(unsigned int a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0

  if ( *(_QWORD *)(a5 + 8) )
    return 4294967274LL;
  if ( rmnet_get_endpoint(a3, a1) )
    return 4294967280LL;
  *(_QWORD *)(a2 + 2696) = a4;
  *(_DWORD *)(a2 + 44) = 0xFFFF;
  *(_QWORD *)(a2 + 496) = 0x800102001D0013LL;
  result = register_netdevice(a2);
  if ( !(_DWORD)result )
  {
    *(_QWORD *)(a5 + 8) = a2;
    *(_BYTE *)a5 = a1;
    ++*(_BYTE *)(a3 + 12);
    *(_QWORD *)(a2 + 2328) = &rmnet_link_ops;
    *(_BYTE *)(a2 + 2688) = a1;
    atomic_store(qmi_rmnet_qos_init(a4, a2, a1), (unsigned __int64 *)(a2 + 3168));
    return 0;
  }
  return result;
}
