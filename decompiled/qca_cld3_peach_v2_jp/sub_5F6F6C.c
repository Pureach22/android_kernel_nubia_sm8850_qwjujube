double __usercall sub_5F6F6C@<D0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X8>)
{
  unsigned __int16 v6; // w9

  atomic_store(v6, (unsigned __int16 *)(a6 - 36));
  return os_if_wifi_pos_send_rsp(a1, a2, a3, a4, a5);
}
