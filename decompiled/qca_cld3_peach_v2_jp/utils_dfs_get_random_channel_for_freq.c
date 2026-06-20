__int64 __fastcall utils_dfs_get_random_channel_for_freq(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        unsigned __int16 *a13,
        __int64 a14)
{
  return utils_dfs_get_vdev_random_channel_for_freq(
           a1,
           0,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           (__int64)a13,
           a13,
           a14);
}
