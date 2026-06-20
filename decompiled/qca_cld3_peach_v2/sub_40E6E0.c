__int64 __usercall sub_40E6E0@<X0>(
        __int64 a1@<X0>,
        __int64 a2@<X1>,
        __int64 a3@<X2>,
        __int64 a4@<X3>,
        unsigned int a5@<W8>)
{
  return lim_restore_pre_channel_switch_state(a1, a2, a3, a4, a5 >> 22);
}
