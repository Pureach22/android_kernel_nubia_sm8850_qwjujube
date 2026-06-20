__int64 __fastcall tme_opt_file_download_show(__int64 a1, __int64 a2, __int64 a3)
{
  return (unsigned int)scnprintf(
                         a3,
                         4096,
                         "Usage: echo [file_type] > /sys/kernel/cnss/tme_opt_file_download\n"
                         "file_type = sec -- For OEM_FUSE file\n"
                         "file_type = rpr -- For RPR file\n"
                         "file_type = dpr -- For DPR file\n");
}
