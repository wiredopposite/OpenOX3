/* Auto-generated from MS documentation. */

#ifndef NTSTATUS_CODES_H
#define NTSTATUS_CODES_H

#include "win32types/types.h"

#define NT_SUCCESS(Status)  ((NTSTATUS)(Status) >= 0)
#define NT_WARNING(Status)  ((ULONG)(Status) >> 30 == 2)
#define NT_ERROR(Status)    ((ULONG)(Status) >> 30 == 3)

#define STATUS_SUCCESS                                                     ((NTSTATUS)0x00000000) /**< The operation completed successfully. */
#define STATUS_WAIT_0                                                      ((NTSTATUS)0x00000000) /**< The caller specified WaitAny for WaitType and one of the dispatcher objects in the Object array has been set to the signaled state. */
#define STATUS_WAIT_1                                                      ((NTSTATUS)0x00000001) /**< The caller specified WaitAny for WaitType and one of the dispatcher objects in the Object array has been set to the signaled state. */
#define STATUS_WAIT_2                                                      ((NTSTATUS)0x00000002) /**< The caller specified WaitAny for WaitType and one of the dispatcher objects in the Object array has been set to the signaled state. */
#define STATUS_WAIT_3                                                      ((NTSTATUS)0x00000003) /**< The caller specified WaitAny for WaitType and one of the dispatcher objects in the Object array has been set to the signaled state. */
#define STATUS_WAIT_63                                                     ((NTSTATUS)0x0000003F) /**< The caller specified WaitAny for WaitType and one of the dispatcher objects in the Object array has been set to the signaled state. */
#define STATUS_ABANDONED                                                   ((NTSTATUS)0x00000080) /**< The caller attempted to wait for a mutex that has been abandoned. */
#define STATUS_ABANDONED_WAIT_0                                            ((NTSTATUS)0x00000080) /**< The caller attempted to wait for a mutex that has been abandoned. */
#define STATUS_ABANDONED_WAIT_63                                           ((NTSTATUS)0x000000BF) /**< The caller attempted to wait for a mutex that has been abandoned. */
#define STATUS_USER_APC                                                    ((NTSTATUS)0x000000C0) /**< A user-mode APC was delivered before the given Interval expired. */
#define STATUS_KERNEL_APC                                                  ((NTSTATUS)0x00000100) /**< A kernel-mode APC was delivered before the given Interval expired. */
#define STATUS_ALERTED                                                     ((NTSTATUS)0x00000101) /**< The delay completed because the thread was alerted. */
#define STATUS_TIMEOUT                                                     ((NTSTATUS)0x00000102) /**< The given Timeout interval expired. */
#define STATUS_PENDING                                                     ((NTSTATUS)0x00000103) /**< The operation that was requested is pending completion. */
#define STATUS_REPARSE                                                     ((NTSTATUS)0x00000104) /**< A reparse should be performed by the Object Manager because the name of the file resulted in a symbolic link. */
#define STATUS_MORE_ENTRIES                                                ((NTSTATUS)0x00000105) /**< Returned by enumeration APIs to indicate more information is available to successive calls. */
#define STATUS_NOT_ALL_ASSIGNED                                            ((NTSTATUS)0x00000106) /**< Indicates not all privileges or groups that are referenced are assigned to the caller. This allows, for example, all privileges to be disabled without having to know exactly which privileges are assigned. */
#define STATUS_SOME_NOT_MAPPED                                             ((NTSTATUS)0x00000107) /**< Some of the information to be translated has not been translated. */
#define STATUS_OPLOCK_BREAK_IN_PROGRESS                                    ((NTSTATUS)0x00000108) /**< An open/create operation completed while an opportunistic lock (oplock) break is underway. */
#define STATUS_VOLUME_MOUNTED                                              ((NTSTATUS)0x00000109) /**< A new volume has been mounted by a file system. */
#define STATUS_RXACT_COMMITTED                                             ((NTSTATUS)0x0000010A) /**< This success level status indicates that the transaction state already exists for the registry subtree but that a transaction commit was previously aborted. The commit has now been completed. */
#define STATUS_NOTIFY_CLEANUP                                              ((NTSTATUS)0x0000010B) /**< Indicates that a notify change request has been completed due to closing the handle that made the notify change request. */
#define STATUS_NOTIFY_ENUM_DIR                                             ((NTSTATUS)0x0000010C) /**< Indicates that a notify change request is being completed and that the information is not being returned in the caller's buffer. The caller now needs to enumerate the files to find the changes. */
#define STATUS_NO_QUOTAS_FOR_ACCOUNT                                       ((NTSTATUS)0x0000010D) /**< {No Quotas} No system quota limits are specifically set for this account. */
#define STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED                            ((NTSTATUS)0x0000010E) /**< {Connect Failure on Primary Transport} An attempt was made to connect to the remote server %hs on the primary transport, but the connection failed. The computer WAS able to connect on a secondary transport. */
#define STATUS_PAGE_FAULT_TRANSITION                                       ((NTSTATUS)0x00000110) /**< The page fault was a transition fault. */
#define STATUS_PAGE_FAULT_DEMAND_ZERO                                      ((NTSTATUS)0x00000111) /**< The page fault was a demand zero fault. */
#define STATUS_PAGE_FAULT_COPY_ON_WRITE                                    ((NTSTATUS)0x00000112) /**< The page fault was a demand zero fault. */
#define STATUS_PAGE_FAULT_GUARD_PAGE                                       ((NTSTATUS)0x00000113) /**< The page fault was a demand zero fault. */
#define STATUS_PAGE_FAULT_PAGING_FILE                                      ((NTSTATUS)0x00000114) /**< The page fault was satisfied by reading from a secondary storage device. */
#define STATUS_CACHE_PAGE_LOCKED                                           ((NTSTATUS)0x00000115) /**< The cached page was locked during operation. */
#define STATUS_CRASH_DUMP                                                  ((NTSTATUS)0x00000116) /**< The crash dump exists in a paging file. */
#define STATUS_BUFFER_ALL_ZEROS                                            ((NTSTATUS)0x00000117) /**< The specified buffer contains all zeros. */
#define STATUS_REPARSE_OBJECT                                              ((NTSTATUS)0x00000118) /**< A reparse should be performed by the Object Manager because the name of the file resulted in a symbolic link. */
#define STATUS_RESOURCE_REQUIREMENTS_CHANGED                               ((NTSTATUS)0x00000119) /**< The device has succeeded a query-stop and its resource requirements have changed. */
#define STATUS_TRANSLATION_COMPLETE                                        ((NTSTATUS)0x00000120) /**< The translator has translated these resources into the global space and no additional translations should be performed. */
#define STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY                             ((NTSTATUS)0x00000121) /**< The directory service evaluated group memberships locally, because it was unable to contact a global catalog server. */
#define STATUS_NOTHING_TO_TERMINATE                                        ((NTSTATUS)0x00000122) /**< A process being terminated has no threads to terminate. */
#define STATUS_PROCESS_NOT_IN_JOB                                          ((NTSTATUS)0x00000123) /**< The specified process is not part of a job. */
#define STATUS_PROCESS_IN_JOB                                              ((NTSTATUS)0x00000124) /**< The specified process is part of a job. */
#define STATUS_VOLSNAP_HIBERNATE_READY                                     ((NTSTATUS)0x00000125) /**< {Volume Shadow Copy Service} The system is now ready for hibernation. */
#define STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY                          ((NTSTATUS)0x00000126) /**< A file system or file system filter driver has successfully completed an FsFilter operation. */
#define STATUS_INTERRUPT_VECTOR_ALREADY_CONNECTED                          ((NTSTATUS)0x00000127) /**< The specified interrupt vector was already connected. */
#define STATUS_INTERRUPT_STILL_CONNECTED                                   ((NTSTATUS)0x00000128) /**< The specified interrupt vector is still connected. */
#define STATUS_PROCESS_CLONED                                              ((NTSTATUS)0x00000129) /**< The current process is a cloned process. */
#define STATUS_FILE_LOCKED_WITH_ONLY_READERS                               ((NTSTATUS)0x0000012A) /**< The file was locked and all users of the file can only read. */
#define STATUS_FILE_LOCKED_WITH_WRITERS                                    ((NTSTATUS)0x0000012B) /**< The file was locked and at least one user of the file can write. */
#define STATUS_RESOURCEMANAGER_READ_ONLY                                   ((NTSTATUS)0x00000202) /**< The specified ResourceManager made no changes or updates to the resource under this transaction. */
#define STATUS_WAIT_FOR_OPLOCK                                             ((NTSTATUS)0x00000367) /**< An operation is blocked and waiting for an oplock. */
#define DBG_EXCEPTION_HANDLED                                              ((NTSTATUS)0x00010001) /**< Debugger handled the exception. */
#define DBG_CONTINUE                                                       ((NTSTATUS)0x00010002) /**< The debugger continued. */
#define STATUS_FLT_IO_COMPLETE                                             ((NTSTATUS)0x001C0001) /**< The IO was completed by a filter. */
#define STATUS_FILE_NOT_AVAILABLE                                          ((NTSTATUS)0xC0000467) /**< The file is temporarily unavailable. */
#define STATUS_SHARE_UNAVAILABLE                                           ((NTSTATUS)0xC0000480) /**< The share is temporarily unavailable. */
#define STATUS_CALLBACK_RETURNED_THREAD_AFFINITY                           ((NTSTATUS)0xC0000721) /**< A threadpool worker thread entered a callback at thread affinity %p and exited at affinity %p. This is unexpected, indicating that the callback missed restoring the priority. */
#define STATUS_OBJECT_NAME_EXISTS                                          ((NTSTATUS)0x40000000) /**< {Object Exists} An attempt was made to create an object but the object name already exists. */
#define STATUS_THREAD_WAS_SUSPENDED                                        ((NTSTATUS)0x40000001) /**< {Thread Suspended} A thread termination occurred while the thread was suspended. The thread resumed, and termination proceeded. */
#define STATUS_WORKING_SET_LIMIT_RANGE                                     ((NTSTATUS)0x40000002) /**< {Working Set Range Error} An attempt was made to set the working set minimum or maximum to values that are outside the allowable range. */
#define STATUS_IMAGE_NOT_AT_BASE                                           ((NTSTATUS)0x40000003) /**< {Image Relocated} An image file could not be mapped at the address that is specified in the image file. Local fixes must be performed on this image. */
#define STATUS_RXACT_STATE_CREATED                                         ((NTSTATUS)0x40000004) /**< This informational level status indicates that a specified registry subtree transaction state did not yet exist and had to be created. */
#define STATUS_SEGMENT_NOTIFICATION                                        ((NTSTATUS)0x40000005) /**< {Segment Load} A virtual DOS machine (VDM) is loading, unloading, or moving an MS-DOS or Win16 program segment image. An exception is raised so that a debugger can load, unload, or track symbols and breakpoints within these 16-bit segments. */
#define STATUS_LOCAL_USER_SESSION_KEY                                      ((NTSTATUS)0x40000006) /**< {Local Session Key} A user session key was requested for a local remote procedure call (RPC) connection. The session key that is returned is a constant value and not unique to this connection. */
#define STATUS_BAD_CURRENT_DIRECTORY                                       ((NTSTATUS)0x40000007) /**< {Invalid Current Directory} The process cannot switch to the startup current directory %hs. Select OK to set the current directory to %hs, or select CANCEL to exit. */
#define STATUS_SERIAL_MORE_WRITES                                          ((NTSTATUS)0x40000008) /**< {Serial IOCTL Complete} A serial I/O operation was completed by another write to a serial port. (The IOCTL_SERIAL_XOFF_COUNTER reached zero.) */
#define STATUS_REGISTRY_RECOVERED                                          ((NTSTATUS)0x40000009) /**< {Registry Recovery} One of the files that contains the system registry data had to be recovered by using a log or alternate copy. The recovery was successful. */
#define STATUS_FT_READ_RECOVERY_FROM_BACKUP                                ((NTSTATUS)0x4000000A) /**< {Redundant Read} To satisfy a read request, the Windows NT operating system fault-tolerant file system successfully read the requested data from a redundant copy. This was done because the file system encountered a failure on a member of the fault-tolerant volume but was unable to reassign the failing area of the device. */
#define STATUS_FT_WRITE_RECOVERY                                           ((NTSTATUS)0x4000000B) /**< {Redundant Write} To satisfy a write request, the Windows NT fault-tolerant file system successfully wrote a redundant copy of the information. This was done because the file system encountered a failure on a member of the fault-tolerant volume but was unable to reassign the failing area of the device. */
#define STATUS_SERIAL_COUNTER_TIMEOUT                                      ((NTSTATUS)0x4000000C) /**< {Serial IOCTL Timeout} A serial I/O operation completed because the time-out period expired. (The IOCTL_SERIAL_XOFF_COUNTER had not reached zero.) */
#define STATUS_NULL_LM_PASSWORD                                            ((NTSTATUS)0x4000000D) /**< {Password Too Complex} The Windows password is too complex to be converted to a LAN Manager password. The LAN Manager password that returned is a NULL string. */
#define STATUS_IMAGE_MACHINE_TYPE_MISMATCH                                 ((NTSTATUS)0x4000000E) /**< {Machine Type Mismatch} The image file %hs is valid but is for a machine type other than the current machine. Select OK to continue, or CANCEL to fail the DLL load. */
#define STATUS_RECEIVE_PARTIAL                                             ((NTSTATUS)0x4000000F) /**< {Partial Data Received} The network transport returned partial data to its client. The remaining data will be sent later. */
#define STATUS_RECEIVE_EXPEDITED                                           ((NTSTATUS)0x40000010) /**< {Expedited Data Received} The network transport returned data to its client that was marked as expedited by the remote system. */
#define STATUS_RECEIVE_PARTIAL_EXPEDITED                                   ((NTSTATUS)0x40000011) /**< {Partial Expedited Data Received} The network transport returned partial data to its client and this data was marked as expedited by the remote system. The remaining data will be sent later. */
#define STATUS_EVENT_DONE                                                  ((NTSTATUS)0x40000012) /**< {TDI Event Done} The TDI indication has completed successfully. */
#define STATUS_EVENT_PENDING                                               ((NTSTATUS)0x40000013) /**< {TDI Event Pending} The TDI indication has entered the pending state. */
#define STATUS_CHECKING_FILE_SYSTEM                                        ((NTSTATUS)0x40000014) /**< Checking file system on %wZ. */
#define STATUS_FATAL_APP_EXIT                                              ((NTSTATUS)0x40000015) /**< {Fatal Application Exit} %hs */
#define STATUS_PREDEFINED_HANDLE                                           ((NTSTATUS)0x40000016) /**< The specified registry key is referenced by a predefined handle. */
#define STATUS_WAS_UNLOCKED                                                ((NTSTATUS)0x40000017) /**< {Page Unlocked} The page protection of a locked page was changed to 'No Access' and the page was unlocked from memory and from the process. */
#define STATUS_SERVICE_NOTIFICATION                                        ((NTSTATUS)0x40000018) /**< %hs */
#define STATUS_WAS_LOCKED                                                  ((NTSTATUS)0x40000019) /**< {Page Locked} One of the pages to lock was already locked. */
#define STATUS_LOG_HARD_ERROR                                              ((NTSTATUS)0x4000001A) /**< Application popup: %1 : %2 */
#define STATUS_ALREADY_WIN32                                               ((NTSTATUS)0x4000001B) /**< A Win32 process already exists. */
#define STATUS_WX86_UNSIMULATE                                             ((NTSTATUS)0x4000001C) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_WX86_CONTINUE                                               ((NTSTATUS)0x4000001D) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_WX86_SINGLE_STEP                                            ((NTSTATUS)0x4000001E) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_WX86_BREAKPOINT                                             ((NTSTATUS)0x4000001F) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_WX86_EXCEPTION_CONTINUE                                     ((NTSTATUS)0x40000020) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_WX86_EXCEPTION_LASTCHANCE                                   ((NTSTATUS)0x40000021) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_WX86_EXCEPTION_CHAIN                                        ((NTSTATUS)0x40000022) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE                             ((NTSTATUS)0x40000023) /**< {Machine Type Mismatch} The image file %hs is valid but is for a machine type other than the current machine. */
#define STATUS_NO_YIELD_PERFORMED                                          ((NTSTATUS)0x40000024) /**< A yield execution was performed and no thread was available to run. */
#define STATUS_TIMER_RESUME_IGNORED                                        ((NTSTATUS)0x40000025) /**< The resume flag to a timer API was ignored. */
#define STATUS_ARBITRATION_UNHANDLED                                       ((NTSTATUS)0x40000026) /**< The arbiter has deferred arbitration of these resources to its parent. */
#define STATUS_CARDBUS_NOT_SUPPORTED                                       ((NTSTATUS)0x40000027) /**< The device has detected a CardBus card in its slot. */
#define STATUS_WX86_CREATEWX86TIB                                          ((NTSTATUS)0x40000028) /**< An exception status code that is used by the Win32 x86 emulation subsystem. */
#define STATUS_MP_PROCESSOR_MISMATCH                                       ((NTSTATUS)0x40000029) /**< The CPUs in this multiprocessor system are not all the same revision level. To use all processors, the operating system restricts itself to the features of the least capable processor in the system. If problems occur with this system, contact the CPU manufacturer to see if this mix of processors is supported. */
#define STATUS_HIBERNATED                                                  ((NTSTATUS)0x4000002A) /**< The system was put into hibernation. */
#define STATUS_RESUME_HIBERNATION                                          ((NTSTATUS)0x4000002B) /**< The system was resumed from hibernation. */
#define STATUS_FIRMWARE_UPDATED                                            ((NTSTATUS)0x4000002C) /**< Windows has detected that the system firmware (BIOS) was updated [previous firmware date = %2, current firmware date %3]. */
#define STATUS_DRIVERS_LEAKING_LOCKED_PAGES                                ((NTSTATUS)0x4000002D) /**< A device driver is leaking locked I/O pages and is causing system degradation. The system has automatically enabled the tracking code to try and catch the culprit. */
#define STATUS_MESSAGE_RETRIEVED                                           ((NTSTATUS)0x4000002E) /**< The ALPC message being canceled has already been retrieved from the queue on the other side. */
#define STATUS_SYSTEM_POWERSTATE_TRANSITION                                ((NTSTATUS)0x4000002F) /**< The system power state is transitioning from %2 to %3. */
#define STATUS_ALPC_CHECK_COMPLETION_LIST                                  ((NTSTATUS)0x40000030) /**< The receive operation was successful. Check the ALPC completion list for the received message. */
#define STATUS_SYSTEM_POWERSTATE_COMPLEX_TRANSITION                        ((NTSTATUS)0x40000031) /**< The system power state is transitioning from %2 to %3 but could enter %4. */
#define STATUS_ACCESS_AUDIT_BY_POLICY                                      ((NTSTATUS)0x40000032) /**< Access to %1 is monitored by policy rule %2. */
#define STATUS_ABANDON_HIBERFILE                                           ((NTSTATUS)0x40000033) /**< A valid hibernation file has been invalidated and should be abandoned. */
#define STATUS_BIZRULES_NOT_ENABLED                                        ((NTSTATUS)0x40000034) /**< Business rule scripts are disabled for the calling application. */
#define STATUS_WAKE_SYSTEM                                                 ((NTSTATUS)0x40000294) /**< The system has awoken. */
#define STATUS_DS_SHUTTING_DOWN                                            ((NTSTATUS)0x40000370) /**< The directory service is shutting down. */
#define DBG_REPLY_LATER                                                    ((NTSTATUS)0x40010001) /**< Debugger will reply later. */
#define DBG_UNABLE_TO_PROVIDE_HANDLE                                       ((NTSTATUS)0x40010002) /**< Debugger cannot provide a handle. */
#define DBG_TERMINATE_THREAD                                               ((NTSTATUS)0x40010003) /**< Debugger terminated the thread. */
#define DBG_TERMINATE_PROCESS                                              ((NTSTATUS)0x40010004) /**< Debugger terminated the process. */
#define DBG_CONTROL_C                                                      ((NTSTATUS)0x40010005) /**< Debugger obtained control of C. */
#define DBG_PRINTEXCEPTION_C                                               ((NTSTATUS)0x40010006) /**< Debugger printed an exception on control C. */
#define DBG_RIPEXCEPTION                                                   ((NTSTATUS)0x40010007) /**< Debugger received a RIP exception. */
#define DBG_CONTROL_BREAK                                                  ((NTSTATUS)0x40010008) /**< Debugger received a control break. */
#define DBG_COMMAND_EXCEPTION                                              ((NTSTATUS)0x40010009) /**< Debugger command communication exception. */
#define RPC_NT_UUID_LOCAL_ONLY                                             ((NTSTATUS)0x40020056) /**< A UUID that is valid only on this computer has been allocated. */
#define RPC_NT_SEND_INCOMPLETE                                             ((NTSTATUS)0x400200AF) /**< Some data remains to be sent in the request buffer. */
#define STATUS_CTX_CDM_CONNECT                                             ((NTSTATUS)0x400A0004) /**< The Client Drive Mapping Service has connected on Terminal Connection. */
#define STATUS_CTX_CDM_DISCONNECT                                          ((NTSTATUS)0x400A0005) /**< The Client Drive Mapping Service has disconnected on Terminal Connection. */
#define STATUS_SXS_RELEASE_ACTIVATION_CONTEXT                              ((NTSTATUS)0x4015000D) /**< A kernel mode component is releasing a reference on an activation context. */
#define STATUS_RECOVERY_NOT_NEEDED                                         ((NTSTATUS)0x40190034) /**< The transactional resource manager is already consistent. Recovery is not needed. */
#define STATUS_RM_ALREADY_STARTED                                          ((NTSTATUS)0x40190035) /**< The transactional resource manager has already been started. */
#define STATUS_LOG_NO_RESTART                                              ((NTSTATUS)0x401A000C) /**< The log service encountered a log stream with no restart area. */
#define STATUS_VIDEO_DRIVER_DEBUG_REPORT_REQUEST                           ((NTSTATUS)0x401B00EC) /**< {Display Driver Recovered From Failure} The %hs display driver has detected a failure and recovered from it. Some graphical operations might have failed. The next time you restart the machine, a dialog box appears, giving you an opportunity to upload data about this failure to Microsoft. */
#define STATUS_GRAPHICS_PARTIAL_DATA_POPULATED                             ((NTSTATUS)0x401E000A) /**< The specified buffer is not big enough to contain the entire requested dataset. Partial data is populated up to the size of the buffer. The caller needs to provide a buffer of the size as specified in the partially populated buffer's content (interface specific). */
#define STATUS_GRAPHICS_DRIVER_MISMATCH                                    ((NTSTATUS)0x401E0117) /**< The kernel driver detected a version mismatch between it and the user mode driver. */
#define STATUS_GRAPHICS_MODE_NOT_PINNED                                    ((NTSTATUS)0x401E0307) /**< No mode is pinned on the specified VidPN source/target. */
#define STATUS_GRAPHICS_NO_PREFERRED_MODE                                  ((NTSTATUS)0x401E031E) /**< The specified mode set does not specify a preference for one of its modes. */
#define STATUS_GRAPHICS_DATASET_IS_EMPTY                                   ((NTSTATUS)0x401E034B) /**< The specified dataset (for example, mode set, frequency range set, descriptor set, or topology) is empty. */
#define STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET                        ((NTSTATUS)0x401E034C) /**< The specified dataset (for example, mode set, frequency range set, descriptor set, or topology) does not contain any more elements. */
#define STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED    ((NTSTATUS)0x401E0351) /**< The specified content transformation is not pinned on the specified VidPN present path. */
#define STATUS_GRAPHICS_UNKNOWN_CHILD_STATUS                               ((NTSTATUS)0x401E042F) /**< The child device presence was not reliably detected. */
#define STATUS_GRAPHICS_LEADLINK_START_DEFERRED                            ((NTSTATUS)0x401E0437) /**< Starting the lead adapter in a linked configuration has been temporarily deferred. */
#define STATUS_GRAPHICS_POLLING_TOO_FREQUENTLY                             ((NTSTATUS)0x401E0439) /**< The display adapter is being polled for children too frequently at the same polling level. */
#define STATUS_GRAPHICS_START_DEFERRED                                     ((NTSTATUS)0x401E043A) /**< Starting the adapter has been temporarily deferred. */
#define STATUS_NDIS_INDICATION_REQUIRED                                    ((NTSTATUS)0x40230001) /**< The request will be completed later by an NDIS status indication. */
#define STATUS_GUARD_PAGE_VIOLATION                                        ((NTSTATUS)0x80000001) /**< {EXCEPTION} Guard Page Exception A page of memory that marks the end of a data structure, such as a stack or an array, has been accessed. */
#define STATUS_DATATYPE_MISALIGNMENT                                       ((NTSTATUS)0x80000002) /**< {EXCEPTION} Alignment Fault A data type misalignment was detected in a load or store instruction. */
#define STATUS_BREAKPOINT                                                  ((NTSTATUS)0x80000003) /**< {EXCEPTION} Breakpoint A breakpoint has been reached. */
#define STATUS_SINGLE_STEP                                                 ((NTSTATUS)0x80000004) /**< {EXCEPTION} Single Step A single step or trace operation has just been completed. */
#define STATUS_BUFFER_OVERFLOW                                             ((NTSTATUS)0x80000005) /**< {Buffer Overflow} The data was too large to fit into the specified buffer. */
#define STATUS_NO_MORE_FILES                                               ((NTSTATUS)0x80000006) /**< {No More Files} No more files were found which match the file specification. */
#define STATUS_WAKE_SYSTEM_DEBUGGER                                        ((NTSTATUS)0x80000007) /**< {Kernel Debugger Awakened} The system debugger was awakened by an interrupt. */
#define STATUS_HANDLES_CLOSED                                              ((NTSTATUS)0x8000000A) /**< {Handles Closed} Handles to objects have been automatically closed because of the requested operation. */
#define STATUS_NO_INHERITANCE                                              ((NTSTATUS)0x8000000B) /**< {Non-Inheritable ACL} An access control list (ACL) contains no components that can be inherited. */
#define STATUS_GUID_SUBSTITUTION_MADE                                      ((NTSTATUS)0x8000000C) /**< {GUID Substitution} During the translation of a globally unique identifier (GUID) to a Windows security ID (SID), no administratively defined GUID prefix was found. A substitute prefix was used, which will not compromise system security. However, this might provide a more restrictive access than intended. */
#define STATUS_PARTIAL_COPY                                                ((NTSTATUS)0x8000000D) /**< Because of protection conflicts, not all the requested bytes could be copied. */
#define STATUS_DEVICE_PAPER_EMPTY                                          ((NTSTATUS)0x8000000E) /**< {Out of Paper} The printer is out of paper. */
#define STATUS_DEVICE_POWERED_OFF                                          ((NTSTATUS)0x8000000F) /**< {Device Power Is Off} The printer power has been turned off. */
#define STATUS_DEVICE_OFF_LINE                                             ((NTSTATUS)0x80000010) /**< {Device Offline} The printer has been taken offline. */
#define STATUS_DEVICE_BUSY                                                 ((NTSTATUS)0x80000011) /**< {Device Busy} The device is currently busy. */
#define STATUS_NO_MORE_EAS                                                 ((NTSTATUS)0x80000012) /**< {No More EAs} No more extended attributes (EAs) were found for the file. */
#define STATUS_INVALID_EA_NAME                                             ((NTSTATUS)0x80000013) /**< {Illegal EA} The specified extended attribute (EA) name contains at least one illegal character. */
#define STATUS_EA_LIST_INCONSISTENT                                        ((NTSTATUS)0x80000014) /**< {Inconsistent EA List} The extended attribute (EA) list is inconsistent. */
#define STATUS_INVALID_EA_FLAG                                             ((NTSTATUS)0x80000015) /**< {Invalid EA Flag} An invalid extended attribute (EA) flag was set. */
#define STATUS_VERIFY_REQUIRED                                             ((NTSTATUS)0x80000016) /**< {Verifying Disk} The media has changed and a verify operation is in progress; therefore, no reads or writes can be performed to the device, except those that are used in the verify operation. */
#define STATUS_EXTRANEOUS_INFORMATION                                      ((NTSTATUS)0x80000017) /**< {Too Much Information} The specified access control list (ACL) contained more information than was expected. */
#define STATUS_RXACT_COMMIT_NECESSARY                                      ((NTSTATUS)0x80000018) /**< This warning level status indicates that the transaction state already exists for the registry subtree, but that a transaction commit was previously aborted. The commit has NOT been completed but has not been rolled back either; therefore, it can still be committed, if needed. */
#define STATUS_NO_MORE_ENTRIES                                             ((NTSTATUS)0x8000001A) /**< {No More Entries} No more entries are available from an enumeration operation. */
#define STATUS_FILEMARK_DETECTED                                           ((NTSTATUS)0x8000001B) /**< {Filemark Found} A filemark was detected. */
#define STATUS_MEDIA_CHANGED                                               ((NTSTATUS)0x8000001C) /**< {Media Changed} The media has changed. */
#define STATUS_BUS_RESET                                                   ((NTSTATUS)0x8000001D) /**< {I/O Bus Reset} An I/O bus reset was detected. */
#define STATUS_END_OF_MEDIA                                                ((NTSTATUS)0x8000001E) /**< {End of Media} The end of the media was encountered. */
#define STATUS_BEGINNING_OF_MEDIA                                          ((NTSTATUS)0x8000001F) /**< The beginning of a tape or partition has been detected. */
#define STATUS_MEDIA_CHECK                                                 ((NTSTATUS)0x80000020) /**< {Media Changed} The media might have changed. */
#define STATUS_SETMARK_DETECTED                                            ((NTSTATUS)0x80000021) /**< A tape access reached a set mark. */
#define STATUS_NO_DATA_DETECTED                                            ((NTSTATUS)0x80000022) /**< During a tape access, the end of the data written is reached. */
#define STATUS_REDIRECTOR_HAS_OPEN_HANDLES                                 ((NTSTATUS)0x80000023) /**< The redirector is in use and cannot be unloaded. */
#define STATUS_SERVER_HAS_OPEN_HANDLES                                     ((NTSTATUS)0x80000024) /**< The server is in use and cannot be unloaded. */
#define STATUS_ALREADY_DISCONNECTED                                        ((NTSTATUS)0x80000025) /**< The specified connection has already been disconnected. */
#define STATUS_LONGJUMP                                                    ((NTSTATUS)0x80000026) /**< A long jump has been executed. */
#define STATUS_CLEANER_CARTRIDGE_INSTALLED                                 ((NTSTATUS)0x80000027) /**< A cleaner cartridge is present in the tape library. */
#define STATUS_PLUGPLAY_QUERY_VETOED                                       ((NTSTATUS)0x80000028) /**< The Plug and Play query operation was not successful. */
#define STATUS_UNWIND_CONSOLIDATE                                          ((NTSTATUS)0x80000029) /**< A frame consolidation has been executed. */
#define STATUS_REGISTRY_HIVE_RECOVERED                                     ((NTSTATUS)0x8000002A) /**< {Registry Hive Recovered} The registry hive (file): %hs was corrupted and it has been recovered. Some data might have been lost. */
#define STATUS_DLL_MIGHT_BE_INSECURE                                       ((NTSTATUS)0x8000002B) /**< The application is attempting to run executable code from the module %hs. This might be insecure. An alternative, %hs, is available. Should the application use the secure module %hs? */
#define STATUS_DLL_MIGHT_BE_INCOMPATIBLE                                   ((NTSTATUS)0x8000002C) /**< The application is loading executable code from the module %hs. This is secure but might be incompatible with previous releases of the operating system. An alternative, %hs, is available. Should the application use the secure module %hs? */
#define STATUS_STOPPED_ON_SYMLINK                                          ((NTSTATUS)0x8000002D) /**< The create operation stopped after reaching a symbolic link. */
#define STATUS_DEVICE_REQUIRES_CLEANING                                    ((NTSTATUS)0x80000288) /**< The device has indicated that cleaning is necessary. */
#define STATUS_DEVICE_DOOR_OPEN                                            ((NTSTATUS)0x80000289) /**< The device has indicated that its door is open. Further operations require it closed and secured. */
#define STATUS_DATA_LOST_REPAIR                                            ((NTSTATUS)0x80000803) /**< Windows discovered a corruption in the file %hs. This file has now been repaired. Check if any data in the file was lost because of the corruption. */
#define DBG_EXCEPTION_NOT_HANDLED                                          ((NTSTATUS)0x80010001) /**< Debugger did not handle the exception. */
#define STATUS_CLUSTER_NODE_ALREADY_UP                                     ((NTSTATUS)0x80130001) /**< The cluster node is already up. */
#define STATUS_CLUSTER_NODE_ALREADY_DOWN                                   ((NTSTATUS)0x80130002) /**< The cluster node is already down. */
#define STATUS_CLUSTER_NETWORK_ALREADY_ONLINE                              ((NTSTATUS)0x80130003) /**< The cluster network is already online. */
#define STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE                             ((NTSTATUS)0x80130004) /**< The cluster network is already offline. */
#define STATUS_CLUSTER_NODE_ALREADY_MEMBER                                 ((NTSTATUS)0x80130005) /**< The cluster node is already a member of the cluster. */
#define STATUS_COULD_NOT_RESIZE_LOG                                        ((NTSTATUS)0x80190009) /**< The log could not be set to the requested size. */
#define STATUS_NO_TXF_METADATA                                             ((NTSTATUS)0x80190029) /**< There is no transaction metadata on the file. */
#define STATUS_CANT_RECOVER_WITH_HANDLE_OPEN                               ((NTSTATUS)0x80190031) /**< The file cannot be recovered because there is a handle still open on it. */
#define STATUS_TXF_METADATA_ALREADY_PRESENT                                ((NTSTATUS)0x80190041) /**< Transaction metadata is already present on this file and cannot be superseded. */
#define STATUS_TRANSACTION_SCOPE_CALLBACKS_NOT_SET                         ((NTSTATUS)0x80190042) /**< A transaction scope could not be entered because the scope handler has not been initialized. */
#define STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD_RECOVERED                  ((NTSTATUS)0x801B00EB) /**< {Display Driver Stopped Responding and recovered} The %hs display driver has stopped working normally. The recovery had been performed. */
#define STATUS_FLT_BUFFER_TOO_SMALL                                        ((NTSTATUS)0x801C0001) /**< {Buffer too small} The buffer is too small to contain the entry. No information has been written to the buffer. */
#define STATUS_FVE_PARTIAL_METADATA                                        ((NTSTATUS)0x80210001) /**< Volume metadata read or write is incomplete. */
#define STATUS_FVE_TRANSIENT_STATE                                         ((NTSTATUS)0x80210002) /**< BitLocker encryption keys were ignored because the volume was in a transient state. */
#define STATUS_UNSUCCESSFUL                                                ((NTSTATUS)0xC0000001) /**< {Operation Failed} The requested operation was unsuccessful. */
#define STATUS_NOT_IMPLEMENTED                                             ((NTSTATUS)0xC0000002) /**< {Not Implemented} The requested operation is not implemented. */
#define STATUS_INVALID_INFO_CLASS                                          ((NTSTATUS)0xC0000003) /**< {Invalid Parameter} The specified information class is not a valid information class for the specified object. */
#define STATUS_INFO_LENGTH_MISMATCH                                        ((NTSTATUS)0xC0000004) /**< The specified information record length does not match the length that is required for the specified information class. */
#define STATUS_ACCESS_VIOLATION                                            ((NTSTATUS)0xC0000005) /**< The instruction at 0x%08lx referenced memory at 0x%08lx. The memory could not be %s. */
#define STATUS_IN_PAGE_ERROR                                               ((NTSTATUS)0xC0000006) /**< The instruction at 0x%08lx referenced memory at 0x%08lx. The required data was not placed into memory because of an I/O error status of 0x%08lx. */
#define STATUS_PAGEFILE_QUOTA                                              ((NTSTATUS)0xC0000007) /**< The page file quota for the process has been exhausted. */
#define STATUS_INVALID_HANDLE                                              ((NTSTATUS)0xC0000008) /**< An invalid HANDLE was specified. */
#define STATUS_BAD_INITIAL_STACK                                           ((NTSTATUS)0xC0000009) /**< An invalid initial stack was specified in a call to NtCreateThread. */
#define STATUS_BAD_INITIAL_PC                                              ((NTSTATUS)0xC000000A) /**< An invalid initial start address was specified in a call to NtCreateThread. */
#define STATUS_INVALID_CID                                                 ((NTSTATUS)0xC000000B) /**< An invalid client ID was specified. */
#define STATUS_TIMER_NOT_CANCELED                                          ((NTSTATUS)0xC000000C) /**< An attempt was made to cancel or set a timer that has an associated APC and the specified thread is not the thread that originally set the timer with an associated APC routine. */
#define STATUS_INVALID_PARAMETER                                           ((NTSTATUS)0xC000000D) /**< An invalid parameter was passed to a service or function. */
#define STATUS_NO_SUCH_DEVICE                                              ((NTSTATUS)0xC000000E) /**< A device that does not exist was specified. */
#define STATUS_NO_SUCH_FILE                                                ((NTSTATUS)0xC000000F) /**< {File Not Found} The file %hs does not exist. */
#define STATUS_INVALID_DEVICE_REQUEST                                      ((NTSTATUS)0xC0000010) /**< The specified request is not a valid operation for the target device. */
#define STATUS_END_OF_FILE                                                 ((NTSTATUS)0xC0000011) /**< The end-of-file marker has been reached. There is no valid data in the file beyond this marker. */
#define STATUS_WRONG_VOLUME                                                ((NTSTATUS)0xC0000012) /**< {Wrong Volume} The wrong volume is in the drive. Insert volume %hs into drive %hs. */
#define STATUS_NO_MEDIA_IN_DEVICE                                          ((NTSTATUS)0xC0000013) /**< {No Disk} There is no disk in the drive. Insert a disk into drive %hs. */
#define STATUS_UNRECOGNIZED_MEDIA                                          ((NTSTATUS)0xC0000014) /**< {Unknown Disk Format} The disk in drive %hs is not formatted properly. Check the disk, and reformat it, if needed. */
#define STATUS_NONEXISTENT_SECTOR                                          ((NTSTATUS)0xC0000015) /**< {Sector Not Found} The specified sector does not exist. */
#define STATUS_MORE_PROCESSING_REQUIRED                                    ((NTSTATUS)0xC0000016) /**< {Still Busy} The specified I/O request packet (IRP) cannot be disposed of because the I/O operation is not complete. */
#define STATUS_NO_MEMORY                                                   ((NTSTATUS)0xC0000017) /**< {Not Enough Quota} Not enough virtual memory or paging file quota is available to complete the specified operation. */
#define STATUS_CONFLICTING_ADDRESSES                                       ((NTSTATUS)0xC0000018) /**< {Conflicting Address Range} The specified address range conflicts with the address space. */
#define STATUS_NOT_MAPPED_VIEW                                             ((NTSTATUS)0xC0000019) /**< The address range to unmap is not a mapped view. */
#define STATUS_UNABLE_TO_FREE_VM                                           ((NTSTATUS)0xC000001A) /**< The virtual memory cannot be freed. */
#define STATUS_UNABLE_TO_DELETE_SECTION                                    ((NTSTATUS)0xC000001B) /**< The specified section cannot be deleted. */
#define STATUS_INVALID_SYSTEM_SERVICE                                      ((NTSTATUS)0xC000001C) /**< An invalid system service was specified in a system service call. */
#define STATUS_ILLEGAL_INSTRUCTION                                         ((NTSTATUS)0xC000001D) /**< {EXCEPTION} Illegal Instruction An attempt was made to execute an illegal instruction. */
#define STATUS_INVALID_LOCK_SEQUENCE                                       ((NTSTATUS)0xC000001E) /**< {Invalid Lock Sequence} An attempt was made to execute an invalid lock sequence. */
#define STATUS_INVALID_VIEW_SIZE                                           ((NTSTATUS)0xC000001F) /**< {Invalid Mapping} An attempt was made to create a view for a section that is bigger than the section. */
#define STATUS_INVALID_FILE_FOR_SECTION                                    ((NTSTATUS)0xC0000020) /**< {Bad File} The attributes of the specified mapping file for a section of memory cannot be read. */
#define STATUS_ALREADY_COMMITTED                                           ((NTSTATUS)0xC0000021) /**< {Already Committed} The specified address range is already committed. */
#define STATUS_ACCESS_DENIED                                               ((NTSTATUS)0xC0000022) /**< {Access Denied} A process has requested access to an object but has not been granted those access rights. */
#define STATUS_BUFFER_TOO_SMALL                                            ((NTSTATUS)0xC0000023) /**< {Buffer Too Small} The buffer is too small to contain the entry. No information has been written to the buffer. */
#define STATUS_OBJECT_TYPE_MISMATCH                                        ((NTSTATUS)0xC0000024) /**< {Wrong Type} There is a mismatch between the type of object that is required by the requested operation and the type of object that is specified in the request. */
#define STATUS_NONCONTINUABLE_EXCEPTION                                    ((NTSTATUS)0xC0000025) /**< {EXCEPTION} Cannot Continue Windows cannot continue from this exception. */
#define STATUS_INVALID_DISPOSITION                                         ((NTSTATUS)0xC0000026) /**< An invalid exception disposition was returned by an exception handler. */
#define STATUS_UNWIND                                                      ((NTSTATUS)0xC0000027) /**< Unwind exception code. */
#define STATUS_BAD_STACK                                                   ((NTSTATUS)0xC0000028) /**< An invalid or unaligned stack was encountered during an unwind operation. */
#define STATUS_INVALID_UNWIND_TARGET                                       ((NTSTATUS)0xC0000029) /**< An invalid unwind target was encountered during an unwind operation. */
#define STATUS_NOT_LOCKED                                                  ((NTSTATUS)0xC000002A) /**< An attempt was made to unlock a page of memory that was not locked. */
#define STATUS_PARITY_ERROR                                                ((NTSTATUS)0xC000002B) /**< A device parity error on an I/O operation. */
#define STATUS_UNABLE_TO_DECOMMIT_VM                                       ((NTSTATUS)0xC000002C) /**< An attempt was made to decommit uncommitted virtual memory. */
#define STATUS_NOT_COMMITTED                                               ((NTSTATUS)0xC000002D) /**< An attempt was made to change the attributes on memory that has not been committed. */
#define STATUS_INVALID_PORT_ATTRIBUTES                                     ((NTSTATUS)0xC000002E) /**< Invalid object attributes specified to NtCreatePort or invalid port attributes specified to NtConnectPort. */
#define STATUS_PORT_MESSAGE_TOO_LONG                                       ((NTSTATUS)0xC000002F) /**< The length of the message that was passed to NtRequestPort or NtRequestWaitReplyPort is longer than the maximum message that is allowed by the port. */
#define STATUS_INVALID_PARAMETER_MIX                                       ((NTSTATUS)0xC0000030) /**< An invalid combination of parameters was specified. */
#define STATUS_INVALID_QUOTA_LOWER                                         ((NTSTATUS)0xC0000031) /**< An attempt was made to lower a quota limit below the current usage. */
#define STATUS_DISK_CORRUPT_ERROR                                          ((NTSTATUS)0xC0000032) /**< {Corrupt Disk} The file system structure on the disk is corrupt and unusable. Run the Chkdsk utility on the volume %hs. */
#define STATUS_OBJECT_NAME_INVALID                                         ((NTSTATUS)0xC0000033) /**< The object name is invalid. */
#define STATUS_OBJECT_NAME_NOT_FOUND                                       ((NTSTATUS)0xC0000034) /**< The object name is not found. */
#define STATUS_OBJECT_NAME_COLLISION                                       ((NTSTATUS)0xC0000035) /**< The object name already exists. */
#define STATUS_PORT_DISCONNECTED                                           ((NTSTATUS)0xC0000037) /**< An attempt was made to send a message to a disconnected communication port. */
#define STATUS_DEVICE_ALREADY_ATTACHED                                     ((NTSTATUS)0xC0000038) /**< An attempt was made to attach to a device that was already attached to another device. */
#define STATUS_OBJECT_PATH_INVALID                                         ((NTSTATUS)0xC0000039) /**< The object path component was not a directory object. */
#define STATUS_OBJECT_PATH_NOT_FOUND                                       ((NTSTATUS)0xC000003A) /**< {Path Not Found} The path %hs does not exist. */
#define STATUS_OBJECT_PATH_SYNTAX_BAD                                      ((NTSTATUS)0xC000003B) /**< The object path component was not a directory object. */
#define STATUS_DATA_OVERRUN                                                ((NTSTATUS)0xC000003C) /**< {Data Overrun} A data overrun error occurred. */
#define STATUS_DATA_LATE_ERROR                                             ((NTSTATUS)0xC000003D) /**< {Data Late} A data late error occurred. */
#define STATUS_DATA_ERROR                                                  ((NTSTATUS)0xC000003E) /**< {Data Error} An error occurred in reading or writing data. */
#define STATUS_CRC_ERROR                                                   ((NTSTATUS)0xC000003F) /**< {Bad CRC} A cyclic redundancy check (CRC) checksum error occurred. */
#define STATUS_SECTION_TOO_BIG                                             ((NTSTATUS)0xC0000040) /**< {Section Too Large} The specified section is too big to map the file. */
#define STATUS_PORT_CONNECTION_REFUSED                                     ((NTSTATUS)0xC0000041) /**< The NtConnectPort request is refused. */
#define STATUS_INVALID_PORT_HANDLE                                         ((NTSTATUS)0xC0000042) /**< The type of port handle is invalid for the operation that is requested. */
#define STATUS_SHARING_VIOLATION                                           ((NTSTATUS)0xC0000043) /**< A file cannot be opened because the share access flags are incompatible. */
#define STATUS_QUOTA_EXCEEDED                                              ((NTSTATUS)0xC0000044) /**< Insufficient quota exists to complete the operation. */
#define STATUS_INVALID_PAGE_PROTECTION                                     ((NTSTATUS)0xC0000045) /**< The specified page protection was not valid. */
#define STATUS_MUTANT_NOT_OWNED                                            ((NTSTATUS)0xC0000046) /**< An attempt to release a mutant object was made by a thread that was not the owner of the mutant object. */
#define STATUS_SEMAPHORE_LIMIT_EXCEEDED                                    ((NTSTATUS)0xC0000047) /**< An attempt was made to release a semaphore such that its maximum count would have been exceeded. */
#define STATUS_PORT_ALREADY_SET                                            ((NTSTATUS)0xC0000048) /**< An attempt was made to set the DebugPort or ExceptionPort of a process, but a port already exists in the process, or an attempt was made to set the CompletionPort of a file but a port was already set in the file, or an attempt was made to set the associated completion port of an ALPC port but it is already set. */
#define STATUS_SECTION_NOT_IMAGE                                           ((NTSTATUS)0xC0000049) /**< An attempt was made to query image information on a section that does not map an image. */
#define STATUS_SUSPEND_COUNT_EXCEEDED                                      ((NTSTATUS)0xC000004A) /**< An attempt was made to suspend a thread whose suspend count was at its maximum. */
#define STATUS_THREAD_IS_TERMINATING                                       ((NTSTATUS)0xC000004B) /**< An attempt was made to suspend a thread that has begun termination. */
#define STATUS_BAD_WORKING_SET_LIMIT                                       ((NTSTATUS)0xC000004C) /**< An attempt was made to set the working set limit to an invalid value (for example, the minimum greater than maximum). */
#define STATUS_INCOMPATIBLE_FILE_MAP                                       ((NTSTATUS)0xC000004D) /**< A section was created to map a file that is not compatible with an already existing section that maps the same file. */
#define STATUS_SECTION_PROTECTION                                          ((NTSTATUS)0xC000004E) /**< A view to a section specifies a protection that is incompatible with the protection of the initial view. */
#define STATUS_EAS_NOT_SUPPORTED                                           ((NTSTATUS)0xC000004F) /**< An operation involving EAs failed because the file system does not support EAs. */
#define STATUS_EA_TOO_LARGE                                                ((NTSTATUS)0xC0000050) /**< An EA operation failed because the EA set is too large. */
#define STATUS_NONEXISTENT_EA_ENTRY                                        ((NTSTATUS)0xC0000051) /**< An EA operation failed because the name or EA index is invalid. */
#define STATUS_NO_EAS_ON_FILE                                              ((NTSTATUS)0xC0000052) /**< The file for which EAs were requested has no EAs. */
#define STATUS_EA_CORRUPT_ERROR                                            ((NTSTATUS)0xC0000053) /**< The EA is corrupt and cannot be read. */
#define STATUS_FILE_LOCK_CONFLICT                                          ((NTSTATUS)0xC0000054) /**< A requested read/write cannot be granted due to a conflicting file lock. */
#define STATUS_LOCK_NOT_GRANTED                                            ((NTSTATUS)0xC0000055) /**< A requested file lock cannot be granted due to other existing locks. */
#define STATUS_DELETE_PENDING                                              ((NTSTATUS)0xC0000056) /**< A non-close operation has been requested of a file object that has a delete pending. */
#define STATUS_CTL_FILE_NOT_SUPPORTED                                      ((NTSTATUS)0xC0000057) /**< An attempt was made to set the control attribute on a file. This attribute is not supported in the destination file system. */
#define STATUS_UNKNOWN_REVISION                                            ((NTSTATUS)0xC0000058) /**< Indicates a revision number that was encountered or specified is not one that is known by the service. It might be a more recent revision than the service is aware of. */
#define STATUS_REVISION_MISMATCH                                           ((NTSTATUS)0xC0000059) /**< Indicates that two revision levels are incompatible. */
#define STATUS_INVALID_OWNER                                               ((NTSTATUS)0xC000005A) /**< Indicates a particular security ID cannot be assigned as the owner of an object. */
#define STATUS_INVALID_PRIMARY_GROUP                                       ((NTSTATUS)0xC000005B) /**< Indicates a particular security ID cannot be assigned as the primary group of an object. */
#define STATUS_NO_IMPERSONATION_TOKEN                                      ((NTSTATUS)0xC000005C) /**< An attempt has been made to operate on an impersonation token by a thread that is not currently impersonating a client. */
#define STATUS_CANT_DISABLE_MANDATORY                                      ((NTSTATUS)0xC000005D) /**< A mandatory group cannot be disabled. */
#define STATUS_NO_LOGON_SERVERS                                            ((NTSTATUS)0xC000005E) /**< No logon servers are currently available to service the logon request. */
#define STATUS_NO_SUCH_LOGON_SESSION                                       ((NTSTATUS)0xC000005F) /**< A specified logon session does not exist. It might already have been terminated. */
#define STATUS_NO_SUCH_PRIVILEGE                                           ((NTSTATUS)0xC0000060) /**< A specified privilege does not exist. */
#define STATUS_PRIVILEGE_NOT_HELD                                          ((NTSTATUS)0xC0000061) /**< A required privilege is not held by the client. */
#define STATUS_INVALID_ACCOUNT_NAME                                        ((NTSTATUS)0xC0000062) /**< The name provided is not a properly formed account name. */
#define STATUS_USER_EXISTS                                                 ((NTSTATUS)0xC0000063) /**< The specified account already exists. */
#define STATUS_NO_SUCH_USER                                                ((NTSTATUS)0xC0000064) /**< The specified account does not exist. */
#define STATUS_GROUP_EXISTS                                                ((NTSTATUS)0xC0000065) /**< The specified group already exists. */
#define STATUS_NO_SUCH_GROUP                                               ((NTSTATUS)0xC0000066) /**< The specified group does not exist. */
#define STATUS_MEMBER_IN_GROUP                                             ((NTSTATUS)0xC0000067) /**< The specified user account is already in the specified group account. Also used to indicate a group cannot be deleted because it contains a member. */
#define STATUS_MEMBER_NOT_IN_GROUP                                         ((NTSTATUS)0xC0000068) /**< The specified user account is not a member of the specified group account. */
#define STATUS_LAST_ADMIN                                                  ((NTSTATUS)0xC0000069) /**< Indicates the requested operation would disable or delete the last remaining administration account. This is not allowed to prevent creating a situation in which the system cannot be administrated. */
#define STATUS_WRONG_PASSWORD                                              ((NTSTATUS)0xC000006A) /**< When trying to update a password, this return status indicates that the value provided as the current password is not correct. */
#define STATUS_ILL_FORMED_PASSWORD                                         ((NTSTATUS)0xC000006B) /**< When trying to update a password, this return status indicates that the value provided for the new password contains values that are not allowed in passwords. */
#define STATUS_PASSWORD_RESTRICTION                                        ((NTSTATUS)0xC000006C) /**< When trying to update a password, this status indicates that some password update rule has been violated. For example, the password might not meet length criteria. */
#define STATUS_LOGON_FAILURE                                               ((NTSTATUS)0xC000006D) /**< The attempted logon is invalid. This is either due to a bad username or authentication information. */
#define STATUS_ACCOUNT_RESTRICTION                                         ((NTSTATUS)0xC000006E) /**< Indicates a referenced user name and authentication information are valid, but some user account restriction has prevented successful authentication (such as time-of-day restrictions). */
#define STATUS_INVALID_LOGON_HOURS                                         ((NTSTATUS)0xC000006F) /**< The user account has time restrictions and cannot be logged onto at this time. */
#define STATUS_INVALID_WORKSTATION                                         ((NTSTATUS)0xC0000070) /**< The user account is restricted so that it cannot be used to log on from the source workstation. */
#define STATUS_PASSWORD_EXPIRED                                            ((NTSTATUS)0xC0000071) /**< The user account password has expired. */
#define STATUS_ACCOUNT_DISABLED                                            ((NTSTATUS)0xC0000072) /**< The referenced account is currently disabled and cannot be logged on to. */
#define STATUS_NONE_MAPPED                                                 ((NTSTATUS)0xC0000073) /**< None of the information to be translated has been translated. */
#define STATUS_TOO_MANY_LUIDS_REQUESTED                                    ((NTSTATUS)0xC0000074) /**< The number of LUIDs requested cannot be allocated with a single allocation. */
#define STATUS_LUIDS_EXHAUSTED                                             ((NTSTATUS)0xC0000075) /**< Indicates there are no more LUIDs to allocate. */
#define STATUS_INVALID_SUB_AUTHORITY                                       ((NTSTATUS)0xC0000076) /**< Indicates the sub-authority value is invalid for the particular use. */
#define STATUS_INVALID_ACL                                                 ((NTSTATUS)0xC0000077) /**< Indicates the ACL structure is not valid. */
#define STATUS_INVALID_SID                                                 ((NTSTATUS)0xC0000078) /**< Indicates the SID structure is not valid. */
#define STATUS_INVALID_SECURITY_DESCR                                      ((NTSTATUS)0xC0000079) /**< Indicates the SECURITY_DESCRIPTOR structure is not valid. */
#define STATUS_PROCEDURE_NOT_FOUND                                         ((NTSTATUS)0xC000007A) /**< Indicates the specified procedure address cannot be found in the DLL. */
#define STATUS_INVALID_IMAGE_FORMAT                                        ((NTSTATUS)0xC000007B) /**< {Bad Image} %hs is either not designed to run on Windows or it contains an error. Try installing the program again using the original installation media or contact your system administrator or the software vendor for support. */
#define STATUS_NO_TOKEN                                                    ((NTSTATUS)0xC000007C) /**< An attempt was made to reference a token that does not exist. This is typically done by referencing the token that is associated with a thread when the thread is not impersonating a client. */
#define STATUS_BAD_INHERITANCE_ACL                                         ((NTSTATUS)0xC000007D) /**< Indicates that an attempt to build either an inherited ACL or ACE was not successful. This can be caused by a number of things. One of the more probable causes is the replacement of a CreatorId with a SID that did not fit into the ACE or ACL. */
#define STATUS_RANGE_NOT_LOCKED                                            ((NTSTATUS)0xC000007E) /**< The range specified in NtUnlockFile was not locked. */
#define STATUS_DISK_FULL                                                   ((NTSTATUS)0xC000007F) /**< An operation failed because the disk was full. */
#define STATUS_SERVER_DISABLED                                             ((NTSTATUS)0xC0000080) /**< The GUID allocation server is disabled at the moment. */
#define STATUS_SERVER_NOT_DISABLED                                         ((NTSTATUS)0xC0000081) /**< The GUID allocation server is enabled at the moment. */
#define STATUS_TOO_MANY_GUIDS_REQUESTED                                    ((NTSTATUS)0xC0000082) /**< Too many GUIDs were requested from the allocation server at once. */
#define STATUS_GUIDS_EXHAUSTED                                             ((NTSTATUS)0xC0000083) /**< The GUIDs could not be allocated because the Authority Agent was exhausted. */
#define STATUS_INVALID_ID_AUTHORITY                                        ((NTSTATUS)0xC0000084) /**< The value provided was an invalid value for an identifier authority. */
#define STATUS_AGENTS_EXHAUSTED                                            ((NTSTATUS)0xC0000085) /**< No more authority agent values are available for the particular identifier authority value. */
#define STATUS_INVALID_VOLUME_LABEL                                        ((NTSTATUS)0xC0000086) /**< An invalid volume label has been specified. */
#define STATUS_SECTION_NOT_EXTENDED                                        ((NTSTATUS)0xC0000087) /**< A mapped section could not be extended. */
#define STATUS_NOT_MAPPED_DATA                                             ((NTSTATUS)0xC0000088) /**< Specified section to flush does not map a data file. */
#define STATUS_RESOURCE_DATA_NOT_FOUND                                     ((NTSTATUS)0xC0000089) /**< Indicates the specified image file did not contain a resource section. */
#define STATUS_RESOURCE_TYPE_NOT_FOUND                                     ((NTSTATUS)0xC000008A) /**< Indicates the specified resource type cannot be found in the image file. */
#define STATUS_RESOURCE_NAME_NOT_FOUND                                     ((NTSTATUS)0xC000008B) /**< Indicates the specified resource name cannot be found in the image file. */
#define STATUS_ARRAY_BOUNDS_EXCEEDED                                       ((NTSTATUS)0xC000008C) /**< {EXCEPTION} Array bounds exceeded. */
#define STATUS_FLOAT_DENORMAL_OPERAND                                      ((NTSTATUS)0xC000008D) /**< {EXCEPTION} Floating-point denormal operand. */
#define STATUS_FLOAT_DIVIDE_BY_ZERO                                        ((NTSTATUS)0xC000008E) /**< {EXCEPTION} Floating-point division by zero. */
#define STATUS_FLOAT_INEXACT_RESULT                                        ((NTSTATUS)0xC000008F) /**< {EXCEPTION} Floating-point inexact result. */
#define STATUS_FLOAT_INVALID_OPERATION                                     ((NTSTATUS)0xC0000090) /**< {EXCEPTION} Floating-point invalid operation. */
#define STATUS_FLOAT_OVERFLOW                                              ((NTSTATUS)0xC0000091) /**< {EXCEPTION} Floating-point overflow. */
#define STATUS_FLOAT_STACK_CHECK                                           ((NTSTATUS)0xC0000092) /**< {EXCEPTION} Floating-point stack check. */
#define STATUS_FLOAT_UNDERFLOW                                             ((NTSTATUS)0xC0000093) /**< {EXCEPTION} Floating-point underflow. */
#define STATUS_INTEGER_DIVIDE_BY_ZERO                                      ((NTSTATUS)0xC0000094) /**< {EXCEPTION} Integer division by zero. */
#define STATUS_INTEGER_OVERFLOW                                            ((NTSTATUS)0xC0000095) /**< {EXCEPTION} Integer overflow. */
#define STATUS_PRIVILEGED_INSTRUCTION                                      ((NTSTATUS)0xC0000096) /**< {EXCEPTION} Privileged instruction. */
#define STATUS_TOO_MANY_PAGING_FILES                                       ((NTSTATUS)0xC0000097) /**< An attempt was made to install more paging files than the system supports. */
#define STATUS_FILE_INVALID                                                ((NTSTATUS)0xC0000098) /**< The volume for a file has been externally altered such that the opened file is no longer valid. */
#define STATUS_ALLOTTED_SPACE_EXCEEDED                                     ((NTSTATUS)0xC0000099) /**< When a block of memory is allotted for future updates, such as the memory allocated to hold discretionary access control and primary group information, successive updates might exceed the amount of memory originally allotted. Because a quota might already have been charged to several processes that have handles to the object, it is not reasonable to alter the size of the allocated memory. Instead, a request that requires more memory than has been allotted must fail and the STATUS_ALLOTTED_SPACE_EXCEEDED error returned. */
#define STATUS_INSUFFICIENT_RESOURCES                                      ((NTSTATUS)0xC000009A) /**< Insufficient system resources exist to complete the API. */
#define STATUS_DFS_EXIT_PATH_FOUND                                         ((NTSTATUS)0xC000009B) /**< An attempt has been made to open a DFS exit path control file. */
#define STATUS_DEVICE_DATA_ERROR                                           ((NTSTATUS)0xC000009C) /**< There are bad blocks (sectors) on the hard disk. */
#define STATUS_DEVICE_NOT_CONNECTED                                        ((NTSTATUS)0xC000009D) /**< There is bad cabling, non-termination, or the controller is not able to obtain access to the hard disk. */
#define STATUS_FREE_VM_NOT_AT_BASE                                         ((NTSTATUS)0xC000009F) /**< Virtual memory cannot be freed because the base address is not the base of the region and a region size of zero was specified. */
#define STATUS_MEMORY_NOT_ALLOCATED                                        ((NTSTATUS)0xC00000A0) /**< An attempt was made to free virtual memory that is not allocated. */
#define STATUS_WORKING_SET_QUOTA                                           ((NTSTATUS)0xC00000A1) /**< The working set is not big enough to allow the requested pages to be locked. */
#define STATUS_MEDIA_WRITE_PROTECTED                                       ((NTSTATUS)0xC00000A2) /**< {Write Protect Error} The disk cannot be written to because it is write-protected. Remove the write protection from the volume %hs in drive %hs. */
#define STATUS_DEVICE_NOT_READY                                            ((NTSTATUS)0xC00000A3) /**< {Drive Not Ready} The drive is not ready for use; its door might be open. Check drive %hs and make sure that a disk is inserted and that the drive door is closed. */
#define STATUS_INVALID_GROUP_ATTRIBUTES                                    ((NTSTATUS)0xC00000A4) /**< The specified attributes are invalid or are incompatible with the attributes for the group as a whole. */
#define STATUS_BAD_IMPERSONATION_LEVEL                                     ((NTSTATUS)0xC00000A5) /**< A specified impersonation level is invalid. Also used to indicate that a required impersonation level was not provided. */
#define STATUS_CANT_OPEN_ANONYMOUS                                         ((NTSTATUS)0xC00000A6) /**< An attempt was made to open an anonymous-level token. Anonymous tokens cannot be opened. */
#define STATUS_BAD_VALIDATION_CLASS                                        ((NTSTATUS)0xC00000A7) /**< The validation information class requested was invalid. */
#define STATUS_BAD_TOKEN_TYPE                                              ((NTSTATUS)0xC00000A8) /**< The type of a token object is inappropriate for its attempted use. */
#define STATUS_BAD_MASTER_BOOT_RECORD                                      ((NTSTATUS)0xC00000A9) /**< The type of a token object is inappropriate for its attempted use. */
#define STATUS_INSTRUCTION_MISALIGNMENT                                    ((NTSTATUS)0xC00000AA) /**< An attempt was made to execute an instruction at an unaligned address and the host system does not support unaligned instruction references. */
#define STATUS_INSTANCE_NOT_AVAILABLE                                      ((NTSTATUS)0xC00000AB) /**< The maximum named pipe instance count has been reached. */
#define STATUS_PIPE_NOT_AVAILABLE                                          ((NTSTATUS)0xC00000AC) /**< An instance of a named pipe cannot be found in the listening state. */
#define STATUS_INVALID_PIPE_STATE                                          ((NTSTATUS)0xC00000AD) /**< The named pipe is not in the connected or closing state. */
#define STATUS_PIPE_BUSY                                                   ((NTSTATUS)0xC00000AE) /**< The specified pipe is set to complete operations and there are current I/O operations queued so that it cannot be changed to queue operations. */
#define STATUS_ILLEGAL_FUNCTION                                            ((NTSTATUS)0xC00000AF) /**< The specified handle is not open to the server end of the named pipe. */
#define STATUS_PIPE_DISCONNECTED                                           ((NTSTATUS)0xC00000B0) /**< The specified named pipe is in the disconnected state. */
#define STATUS_PIPE_CLOSING                                                ((NTSTATUS)0xC00000B1) /**< The specified named pipe is in the closing state. */
#define STATUS_PIPE_CONNECTED                                              ((NTSTATUS)0xC00000B2) /**< The specified named pipe is in the connected state. */
#define STATUS_PIPE_LISTENING                                              ((NTSTATUS)0xC00000B3) /**< The specified named pipe is in the listening state. */
#define STATUS_INVALID_READ_MODE                                           ((NTSTATUS)0xC00000B4) /**< The specified named pipe is not in message mode. */
#define STATUS_IO_TIMEOUT                                                  ((NTSTATUS)0xC00000B5) /**< {Device Timeout} The specified I/O operation on %hs was not completed before the time-out period expired. */
#define STATUS_FILE_FORCED_CLOSED                                          ((NTSTATUS)0xC00000B6) /**< The specified file has been closed by another process. */
#define STATUS_PROFILING_NOT_STARTED                                       ((NTSTATUS)0xC00000B7) /**< Profiling is not started. */
#define STATUS_PROFILING_NOT_STOPPED                                       ((NTSTATUS)0xC00000B8) /**< Profiling is not stopped. */
#define STATUS_COULD_NOT_INTERPRET                                         ((NTSTATUS)0xC00000B9) /**< The passed ACL did not contain the minimum required information. */
#define STATUS_FILE_IS_A_DIRECTORY                                         ((NTSTATUS)0xC00000BA) /**< The file that was specified as a target is a directory, and the caller specified that it could be anything but a directory. */
#define STATUS_NOT_SUPPORTED                                               ((NTSTATUS)0xC00000BB) /**< The request is not supported. */
#define STATUS_REMOTE_NOT_LISTENING                                        ((NTSTATUS)0xC00000BC) /**< This remote computer is not listening. */
#define STATUS_DUPLICATE_NAME                                              ((NTSTATUS)0xC00000BD) /**< A duplicate name exists on the network. */
#define STATUS_BAD_NETWORK_PATH                                            ((NTSTATUS)0xC00000BE) /**< The network path cannot be located. */
#define STATUS_NETWORK_BUSY                                                ((NTSTATUS)0xC00000BF) /**< The network is busy. */
#define STATUS_DEVICE_DOES_NOT_EXIST                                       ((NTSTATUS)0xC00000C0) /**< This device does not exist. */
#define STATUS_TOO_MANY_COMMANDS                                           ((NTSTATUS)0xC00000C1) /**< The network BIOS command limit has been reached. */
#define STATUS_ADAPTER_HARDWARE_ERROR                                      ((NTSTATUS)0xC00000C2) /**< An I/O adapter hardware error has occurred. */
#define STATUS_INVALID_NETWORK_RESPONSE                                    ((NTSTATUS)0xC00000C3) /**< The network responded incorrectly. */
#define STATUS_UNEXPECTED_NETWORK_ERROR                                    ((NTSTATUS)0xC00000C4) /**< An unexpected network error occurred. */
#define STATUS_BAD_REMOTE_ADAPTER                                          ((NTSTATUS)0xC00000C5) /**< The remote adapter is not compatible. */
#define STATUS_PRINT_QUEUE_FULL                                            ((NTSTATUS)0xC00000C6) /**< The print queue is full. */
#define STATUS_NO_SPOOL_SPACE                                              ((NTSTATUS)0xC00000C7) /**< Space to store the file that is waiting to be printed is not available on the server. */
#define STATUS_PRINT_CANCELLED                                             ((NTSTATUS)0xC00000C8) /**< The requested print file has been canceled. */
#define STATUS_NETWORK_NAME_DELETED                                        ((NTSTATUS)0xC00000C9) /**< The network name was deleted. */
#define STATUS_NETWORK_ACCESS_DENIED                                       ((NTSTATUS)0xC00000CA) /**< Network access is denied. */
#define STATUS_BAD_DEVICE_TYPE                                             ((NTSTATUS)0xC00000CB) /**< {Incorrect Network Resource Type} The specified device type (LPT, for example) conflicts with the actual device type on the remote resource. */
#define STATUS_BAD_NETWORK_NAME                                            ((NTSTATUS)0xC00000CC) /**< {Network Name Not Found} The specified share name cannot be found on the remote server. */
#define STATUS_TOO_MANY_NAMES                                              ((NTSTATUS)0xC00000CD) /**< The name limit for the network adapter card of the local computer was exceeded. */
#define STATUS_TOO_MANY_SESSIONS                                           ((NTSTATUS)0xC00000CE) /**< The network BIOS session limit was exceeded. */
#define STATUS_SHARING_PAUSED                                              ((NTSTATUS)0xC00000CF) /**< File sharing has been temporarily paused. */
#define STATUS_REQUEST_NOT_ACCEPTED                                        ((NTSTATUS)0xC00000D0) /**< No more connections can be made to this remote computer at this time because the computer has already accepted the maximum number of connections. */
#define STATUS_REDIRECTOR_PAUSED                                           ((NTSTATUS)0xC00000D1) /**< Print or disk redirection is temporarily paused. */
#define STATUS_NET_WRITE_FAULT                                             ((NTSTATUS)0xC00000D2) /**< A network data fault occurred. */
#define STATUS_PROFILING_AT_LIMIT                                          ((NTSTATUS)0xC00000D3) /**< The number of active profiling objects is at the maximum and no more can be started. */
#define STATUS_NOT_SAME_DEVICE                                             ((NTSTATUS)0xC00000D4) /**< {Incorrect Volume} The destination file of a rename request is located on a different device than the source of the rename request. */
#define STATUS_FILE_RENAMED                                                ((NTSTATUS)0xC00000D5) /**< The specified file has been renamed and thus cannot be modified. */
#define STATUS_VIRTUAL_CIRCUIT_CLOSED                                      ((NTSTATUS)0xC00000D6) /**< {Network Request Timeout} The session with a remote server has been disconnected because the time-out interval for a request has expired. */
#define STATUS_NO_SECURITY_ON_OBJECT                                       ((NTSTATUS)0xC00000D7) /**< Indicates an attempt was made to operate on the security of an object that does not have security associated with it. */
#define STATUS_CANT_WAIT                                                   ((NTSTATUS)0xC00000D8) /**< Used to indicate that an operation cannot continue without blocking for I/O. */
#define STATUS_PIPE_EMPTY                                                  ((NTSTATUS)0xC00000D9) /**< Used to indicate that a read operation was done on an empty pipe. */
#define STATUS_CANT_ACCESS_DOMAIN_INFO                                     ((NTSTATUS)0xC00000DA) /**< Configuration information could not be read from the domain controller, either because the machine is unavailable or access has been denied. */
#define STATUS_CANT_TERMINATE_SELF                                         ((NTSTATUS)0xC00000DB) /**< Indicates that a thread attempted to terminate itself by default (called NtTerminateThread with NULL) and it was the last thread in the current process. */
#define STATUS_INVALID_SERVER_STATE                                        ((NTSTATUS)0xC00000DC) /**< Indicates the Sam Server was in the wrong state to perform the desired operation. */
#define STATUS_INVALID_DOMAIN_STATE                                        ((NTSTATUS)0xC00000DD) /**< Indicates the domain was in the wrong state to perform the desired operation. */
#define STATUS_INVALID_DOMAIN_ROLE                                         ((NTSTATUS)0xC00000DE) /**< This operation is only allowed for the primary domain controller of the domain. */
#define STATUS_NO_SUCH_DOMAIN                                              ((NTSTATUS)0xC00000DF) /**< The specified domain did not exist. */
#define STATUS_DOMAIN_EXISTS                                               ((NTSTATUS)0xC00000E0) /**< The specified domain already exists. */
#define STATUS_DOMAIN_LIMIT_EXCEEDED                                       ((NTSTATUS)0xC00000E1) /**< An attempt was made to exceed the limit on the number of domains per server for this release. */
#define STATUS_OPLOCK_NOT_GRANTED                                          ((NTSTATUS)0xC00000E2) /**< An error status returned when the opportunistic lock (oplock) request is denied. */
#define STATUS_INVALID_OPLOCK_PROTOCOL                                     ((NTSTATUS)0xC00000E3) /**< An error status returned when an invalid opportunistic lock (oplock) acknowledgment is received by a file system. */
#define STATUS_INTERNAL_DB_CORRUPTION                                      ((NTSTATUS)0xC00000E4) /**< This error indicates that the requested operation cannot be completed due to a catastrophic media failure or an on-disk data structure corruption. */
#define STATUS_INTERNAL_ERROR                                              ((NTSTATUS)0xC00000E5) /**< An internal error occurred. */
#define STATUS_GENERIC_NOT_MAPPED                                          ((NTSTATUS)0xC00000E6) /**< Indicates generic access types were contained in an access mask which should already be mapped to non-generic access types. */
#define STATUS_BAD_DESCRIPTOR_FORMAT                                       ((NTSTATUS)0xC00000E7) /**< Indicates a security descriptor is not in the necessary format (absolute or self-relative). */
#define STATUS_INVALID_USER_BUFFER                                         ((NTSTATUS)0xC00000E8) /**< An access to a user buffer failed at an expected point in time. This code is defined because the caller does not want to accept STATUS_ACCESS_VIOLATION in its filter. */
#define STATUS_UNEXPECTED_IO_ERROR                                         ((NTSTATUS)0xC00000E9) /**< If an I/O error that is not defined in the standard FsRtl filter is returned, it is converted to the following error, which is guaranteed to be in the filter. In this case, information is lost; however, the filter correctly handles the exception. */
#define STATUS_UNEXPECTED_MM_CREATE_ERR                                    ((NTSTATUS)0xC00000EA) /**< If an MM error that is not defined in the standard FsRtl filter is returned, it is converted to one of the following errors, which are guaranteed to be in the filter. In this case, information is lost; however, the filter correctly handles the exception. */
#define STATUS_UNEXPECTED_MM_MAP_ERROR                                     ((NTSTATUS)0xC00000EB) /**< If an MM error that is not defined in the standard FsRtl filter is returned, it is converted to one of the following errors, which are guaranteed to be in the filter. In this case, information is lost; however, the filter correctly handles the exception. */
#define STATUS_UNEXPECTED_MM_EXTEND_ERR                                    ((NTSTATUS)0xC00000EC) /**< If an MM error that is not defined in the standard FsRtl filter is returned, it is converted to one of the following errors, which are guaranteed to be in the filter. In this case, information is lost; however, the filter correctly handles the exception. */
#define STATUS_NOT_LOGON_PROCESS                                           ((NTSTATUS)0xC00000ED) /**< The requested action is restricted for use by logon processes only. The calling process has not registered as a logon process. */
#define STATUS_LOGON_SESSION_EXISTS                                        ((NTSTATUS)0xC00000EE) /**< An attempt has been made to start a new session manager or LSA logon session by using an ID that is already in use. */
#define STATUS_INVALID_PARAMETER_1                                         ((NTSTATUS)0xC00000EF) /**< An invalid parameter was passed to a service or function as the first argument. */
#define STATUS_INVALID_PARAMETER_2                                         ((NTSTATUS)0xC00000F0) /**< An invalid parameter was passed to a service or function as the second argument. */
#define STATUS_INVALID_PARAMETER_3                                         ((NTSTATUS)0xC00000F1) /**< An invalid parameter was passed to a service or function as the third argument. */
#define STATUS_INVALID_PARAMETER_4                                         ((NTSTATUS)0xC00000F2) /**< An invalid parameter was passed to a service or function as the fourth argument. */
#define STATUS_INVALID_PARAMETER_5                                         ((NTSTATUS)0xC00000F3) /**< An invalid parameter was passed to a service or function as the fifth argument. */
#define STATUS_INVALID_PARAMETER_6                                         ((NTSTATUS)0xC00000F4) /**< An invalid parameter was passed to a service or function as the sixth argument. */
#define STATUS_INVALID_PARAMETER_7                                         ((NTSTATUS)0xC00000F5) /**< An invalid parameter was passed to a service or function as the seventh argument. */
#define STATUS_INVALID_PARAMETER_8                                         ((NTSTATUS)0xC00000F6) /**< An invalid parameter was passed to a service or function as the eighth argument. */
#define STATUS_INVALID_PARAMETER_9                                         ((NTSTATUS)0xC00000F7) /**< An invalid parameter was passed to a service or function as the ninth argument. */
#define STATUS_INVALID_PARAMETER_10                                        ((NTSTATUS)0xC00000F8) /**< An invalid parameter was passed to a service or function as the tenth argument. */
#define STATUS_INVALID_PARAMETER_11                                        ((NTSTATUS)0xC00000F9) /**< An invalid parameter was passed to a service or function as the eleventh argument. */
#define STATUS_INVALID_PARAMETER_12                                        ((NTSTATUS)0xC00000FA) /**< An invalid parameter was passed to a service or function as the twelfth argument. */
#define STATUS_REDIRECTOR_NOT_STARTED                                      ((NTSTATUS)0xC00000FB) /**< An attempt was made to access a network file, but the network software was not yet started. */
#define STATUS_REDIRECTOR_STARTED                                          ((NTSTATUS)0xC00000FC) /**< An attempt was made to start the redirector, but the redirector has already been started. */
#define STATUS_STACK_OVERFLOW                                              ((NTSTATUS)0xC00000FD) /**< A new guard page for the stack cannot be created. */
#define STATUS_NO_SUCH_PACKAGE                                             ((NTSTATUS)0xC00000FE) /**< A specified authentication package is unknown. */
#define STATUS_BAD_FUNCTION_TABLE                                          ((NTSTATUS)0xC00000FF) /**< A malformed function table was encountered during an unwind operation. */
#define STATUS_VARIABLE_NOT_FOUND                                          ((NTSTATUS)0xC0000100) /**< Indicates the specified environment variable name was not found in the specified environment block. */
#define STATUS_DIRECTORY_NOT_EMPTY                                         ((NTSTATUS)0xC0000101) /**< Indicates that the directory trying to be deleted is not empty. */
#define STATUS_FILE_CORRUPT_ERROR                                          ((NTSTATUS)0xC0000102) /**< {Corrupt File} The file or directory %hs is corrupt and unreadable. Run the Chkdsk utility. */
#define STATUS_NOT_A_DIRECTORY                                             ((NTSTATUS)0xC0000103) /**< A requested opened file is not a directory. */
#define STATUS_BAD_LOGON_SESSION_STATE                                     ((NTSTATUS)0xC0000104) /**< The logon session is not in a state that is consistent with the requested operation. */
#define STATUS_LOGON_SESSION_COLLISION                                     ((NTSTATUS)0xC0000105) /**< An internal LSA error has occurred. An authentication package has requested the creation of a logon session but the ID of an already existing logon session has been specified. */
#define STATUS_NAME_TOO_LONG                                               ((NTSTATUS)0xC0000106) /**< A specified name string is too long for its intended use. */
#define STATUS_FILES_OPEN                                                  ((NTSTATUS)0xC0000107) /**< The user attempted to force close the files on a redirected drive, but there were opened files on the drive, and the user did not specify a sufficient level of force. */
#define STATUS_CONNECTION_IN_USE                                           ((NTSTATUS)0xC0000108) /**< The user attempted to force close the files on a redirected drive, but there were opened directories on the drive, and the user did not specify a sufficient level of force. */
#define STATUS_MESSAGE_NOT_FOUND                                           ((NTSTATUS)0xC0000109) /**< RtlFindMessage could not locate the requested message ID in the message table resource. */
#define STATUS_PROCESS_IS_TERMINATING                                      ((NTSTATUS)0xC000010A) /**< An attempt was made to duplicate an object handle into or out of an exiting process. */
#define STATUS_INVALID_LOGON_TYPE                                          ((NTSTATUS)0xC000010B) /**< Indicates an invalid value has been provided for the LogonType requested. */
#define STATUS_NO_GUID_TRANSLATION                                         ((NTSTATUS)0xC000010C) /**< Indicates that an attempt was made to assign protection to a file system file or directory and one of the SIDs in the security descriptor could not be translated into a GUID that could be stored by the file system. This causes the protection attempt to fail, which might cause a file creation attempt to fail. */
#define STATUS_CANNOT_IMPERSONATE                                          ((NTSTATUS)0xC000010D) /**< Indicates that an attempt has been made to impersonate via a named pipe that has not yet been read from. */
#define STATUS_IMAGE_ALREADY_LOADED                                        ((NTSTATUS)0xC000010E) /**< Indicates that the specified image is already loaded. */
#define STATUS_NO_LDT                                                      ((NTSTATUS)0xC0000117) /**< Indicates that an attempt was made to change the size of the LDT for a process that has no LDT. */
#define STATUS_INVALID_LDT_SIZE                                            ((NTSTATUS)0xC0000118) /**< Indicates that an attempt was made to grow an LDT by setting its size, or that the size was not an even number of selectors. */
#define STATUS_INVALID_LDT_OFFSET                                          ((NTSTATUS)0xC0000119) /**< Indicates that the starting value for the LDT information was not an integral multiple of the selector size. */
#define STATUS_INVALID_LDT_DESCRIPTOR                                      ((NTSTATUS)0xC000011A) /**< Indicates that the user supplied an invalid descriptor when trying to set up LDT descriptors. */
#define STATUS_INVALID_IMAGE_NE_FORMAT                                     ((NTSTATUS)0xC000011B) /**< The specified image file did not have the correct format. It appears to be NE format. */
#define STATUS_RXACT_INVALID_STATE                                         ((NTSTATUS)0xC000011C) /**< Indicates that the transaction state of a registry subtree is incompatible with the requested operation. For example, a request has been made to start a new transaction with one already in progress, or a request has been made to apply a transaction when one is not currently in progress. */
#define STATUS_RXACT_COMMIT_FAILURE                                        ((NTSTATUS)0xC000011D) /**< Indicates an error has occurred during a registry transaction commit. The database has been left in an unknown, but probably inconsistent, state. The state of the registry transaction is left as COMMITTING. */
#define STATUS_MAPPED_FILE_SIZE_ZERO                                       ((NTSTATUS)0xC000011E) /**< An attempt was made to map a file of size zero with the maximum size specified as zero. */
#define STATUS_TOO_MANY_OPENED_FILES                                       ((NTSTATUS)0xC000011F) /**< Too many files are opened on a remote server. This error should only be returned by the Windows redirector on a remote drive. */
#define STATUS_CANCELLED                                                   ((NTSTATUS)0xC0000120) /**< The I/O request was canceled. */
#define STATUS_CANNOT_DELETE                                               ((NTSTATUS)0xC0000121) /**< An attempt has been made to remove a file or directory that cannot be deleted. */
#define STATUS_INVALID_COMPUTER_NAME                                       ((NTSTATUS)0xC0000122) /**< Indicates a name that was specified as a remote computer name is syntactically invalid. */
#define STATUS_FILE_DELETED                                                ((NTSTATUS)0xC0000123) /**< An I/O request other than close was performed on a file after it was deleted, which can only happen to a request that did not complete before the last handle was closed via NtClose. */
#define STATUS_SPECIAL_ACCOUNT                                             ((NTSTATUS)0xC0000124) /**< Indicates an operation that is incompatible with built-in accounts has been attempted on a built-in (special) SAM account. For example, built-in accounts cannot be deleted. */
#define STATUS_SPECIAL_GROUP                                               ((NTSTATUS)0xC0000125) /**< The operation requested cannot be performed on the specified group because it is a built-in special group. */
#define STATUS_SPECIAL_USER                                                ((NTSTATUS)0xC0000126) /**< The operation requested cannot be performed on the specified user because it is a built-in special user. */
#define STATUS_MEMBERS_PRIMARY_GROUP                                       ((NTSTATUS)0xC0000127) /**< Indicates a member cannot be removed from a group because the group is currently the member's primary group. */
#define STATUS_FILE_CLOSED                                                 ((NTSTATUS)0xC0000128) /**< An I/O request other than close and several other special case operations was attempted using a file object that had already been closed. */
#define STATUS_TOO_MANY_THREADS                                            ((NTSTATUS)0xC0000129) /**< Indicates a process has too many threads to perform the requested action. For example, assignment of a primary token can be performed only when a process has zero or one threads. */
#define STATUS_THREAD_NOT_IN_PROCESS                                       ((NTSTATUS)0xC000012A) /**< An attempt was made to operate on a thread within a specific process, but the specified thread is not in the specified process. */
#define STATUS_TOKEN_ALREADY_IN_USE                                        ((NTSTATUS)0xC000012B) /**< An attempt was made to establish a token for use as a primary token but the token is already in use. A token can only be the primary token of one process at a time. */
#define STATUS_PAGEFILE_QUOTA_EXCEEDED                                     ((NTSTATUS)0xC000012C) /**< The page file quota was exceeded. */
#define STATUS_COMMITMENT_LIMIT                                            ((NTSTATUS)0xC000012D) /**< {Out of Virtual Memory} Your system is low on virtual memory. To ensure that Windows runs correctly, increase the size of your virtual memory paging file. For more information, see Help. */
#define STATUS_INVALID_IMAGE_LE_FORMAT                                     ((NTSTATUS)0xC000012E) /**< The specified image file did not have the correct format: it appears to be LE format. */
#define STATUS_INVALID_IMAGE_NOT_MZ                                        ((NTSTATUS)0xC000012F) /**< The specified image file did not have the correct format: it did not have an initial MZ. */
#define STATUS_INVALID_IMAGE_PROTECT                                       ((NTSTATUS)0xC0000130) /**< The specified image file did not have the correct format: it did not have a proper e_lfarlc in the MZ header. */
#define STATUS_INVALID_IMAGE_WIN_16                                        ((NTSTATUS)0xC0000131) /**< The specified image file did not have the correct format: it appears to be a 16-bit Windows image. */
#define STATUS_LOGON_SERVER_CONFLICT                                       ((NTSTATUS)0xC0000132) /**< The Netlogon service cannot start because another Netlogon service running in the domain conflicts with the specified role. */
#define STATUS_TIME_DIFFERENCE_AT_DC                                       ((NTSTATUS)0xC0000133) /**< The time at the primary domain controller is different from the time at the backup domain controller or member server by too large an amount. */
#define STATUS_SYNCHRONIZATION_REQUIRED                                    ((NTSTATUS)0xC0000134) /**< On applicable Windows Server releases, the SAM database is significantly out of synchronization with the copy on the domain controller. A complete synchronization is required. */
#define STATUS_DLL_NOT_FOUND                                               ((NTSTATUS)0xC0000135) /**< {Unable To Locate Component} This application has failed to start because %hs was not found. Reinstalling the application might fix this problem. */
#define STATUS_OPEN_FAILED                                                 ((NTSTATUS)0xC0000136) /**< The NtCreateFile API failed. This error should never be returned to an application; it is a place holder for the Windows LAN Manager Redirector to use in its internal error-mapping routines. */
#define STATUS_IO_PRIVILEGE_FAILED                                         ((NTSTATUS)0xC0000137) /**< {Privilege Failed} The I/O permissions for the process could not be changed. */
#define STATUS_ORDINAL_NOT_FOUND                                           ((NTSTATUS)0xC0000138) /**< {Ordinal Not Found} The ordinal %ld could not be located in the dynamic link library %hs. */
#define STATUS_ENTRYPOINT_NOT_FOUND                                        ((NTSTATUS)0xC0000139) /**< {Entry Point Not Found} The procedure entry point %hs could not be located in the dynamic link library %hs. */
#define STATUS_CONTROL_C_EXIT                                              ((NTSTATUS)0xC000013A) /**< {Application Exit by CTRL+C} The application terminated as a result of a CTRL+C. */
#define STATUS_LOCAL_DISCONNECT                                            ((NTSTATUS)0xC000013B) /**< {Virtual Circuit Closed} The network transport on your computer has closed a network connection. There might or might not be I/O requests outstanding. */
#define STATUS_REMOTE_DISCONNECT                                           ((NTSTATUS)0xC000013C) /**< {Virtual Circuit Closed} The network transport on a remote computer has closed a network connection. There might or might not be I/O requests outstanding. */
#define STATUS_REMOTE_RESOURCES                                            ((NTSTATUS)0xC000013D) /**< {Insufficient Resources on Remote Computer} The remote computer has insufficient resources to complete the network request. For example, the remote computer might not have enough available memory to carry out the request at this time. */
#define STATUS_LINK_FAILED                                                 ((NTSTATUS)0xC000013E) /**< {Virtual Circuit Closed} An existing connection (virtual circuit) has been broken at the remote computer. There is probably something wrong with the network software protocol or the network hardware on the remote computer. */
#define STATUS_LINK_TIMEOUT                                                ((NTSTATUS)0xC000013F) /**< {Virtual Circuit Closed} The network transport on your computer has closed a network connection because it had to wait too long for a response from the remote computer. */
#define STATUS_INVALID_CONNECTION                                          ((NTSTATUS)0xC0000140) /**< The connection handle that was given to the transport was invalid. */
#define STATUS_INVALID_ADDRESS                                             ((NTSTATUS)0xC0000141) /**< The address handle that was given to the transport was invalid. */
#define STATUS_DLL_INIT_FAILED                                             ((NTSTATUS)0xC0000142) /**< {DLL Initialization Failed} Initialization of the dynamic link library %hs failed. The process is terminating abnormally. */
#define STATUS_MISSING_SYSTEMFILE                                          ((NTSTATUS)0xC0000143) /**< {Missing System File} The required system file %hs is bad or missing. */
#define STATUS_UNHANDLED_EXCEPTION                                         ((NTSTATUS)0xC0000144) /**< {Application Error} The exception %s (0x%08lx) occurred in the application at location 0x%08lx. */
#define STATUS_APP_INIT_FAILURE                                            ((NTSTATUS)0xC0000145) /**< {Application Error} The application failed to initialize properly (0x%lx). Click OK to terminate the application. */
#define STATUS_PAGEFILE_CREATE_FAILED                                      ((NTSTATUS)0xC0000146) /**< {Unable to Create Paging File} The creation of the paging file %hs failed (%lx). The requested size was %ld. */
#define STATUS_NO_PAGEFILE                                                 ((NTSTATUS)0xC0000147) /**< {No Paging File Specified} No paging file was specified in the system configuration. */
#define STATUS_INVALID_LEVEL                                               ((NTSTATUS)0xC0000148) /**< {Incorrect System Call Level} An invalid level was passed into the specified system call. */
#define STATUS_WRONG_PASSWORD_CORE                                         ((NTSTATUS)0xC0000149) /**< {Incorrect Password to LAN Manager Server} You specified an incorrect password to a LAN Manager 2.x or MS-NET server. */
#define STATUS_ILLEGAL_FLOAT_CONTEXT                                       ((NTSTATUS)0xC000014A) /**< {EXCEPTION} A real-mode application issued a floating-point instruction and floating-point hardware is not present. */
#define STATUS_PIPE_BROKEN                                                 ((NTSTATUS)0xC000014B) /**< The pipe operation has failed because the other end of the pipe has been closed. */
#define STATUS_REGISTRY_CORRUPT                                            ((NTSTATUS)0xC000014C) /**< {The Registry Is Corrupt} The structure of one of the files that contains registry data is corrupt; the image of the file in memory is corrupt; or the file could not be recovered because the alternate copy or log was absent or corrupt. */
#define STATUS_REGISTRY_IO_FAILED                                          ((NTSTATUS)0xC000014D) /**< An I/O operation initiated by the Registry failed and cannot be recovered. The registry could not read in, write out, or flush one of the files that contain the system's image of the registry. */
#define STATUS_NO_EVENT_PAIR                                               ((NTSTATUS)0xC000014E) /**< An event pair synchronization operation was performed using the thread-specific client/server event pair object, but no event pair object was associated with the thread. */
#define STATUS_UNRECOGNIZED_VOLUME                                         ((NTSTATUS)0xC000014F) /**< The volume does not contain a recognized file system. Be sure that all required file system drivers are loaded and that the volume is not corrupt. */
#define STATUS_SERIAL_NO_DEVICE_INITED                                     ((NTSTATUS)0xC0000150) /**< No serial device was successfully initialized. The serial driver will unload. */
#define STATUS_NO_SUCH_ALIAS                                               ((NTSTATUS)0xC0000151) /**< The specified local group does not exist. */
#define STATUS_MEMBER_NOT_IN_ALIAS                                         ((NTSTATUS)0xC0000152) /**< The specified account name is not a member of the group. */
#define STATUS_MEMBER_IN_ALIAS                                             ((NTSTATUS)0xC0000153) /**< The specified account name is already a member of the group. */
#define STATUS_ALIAS_EXISTS                                                ((NTSTATUS)0xC0000154) /**< The specified local group already exists. */
#define STATUS_LOGON_NOT_GRANTED                                           ((NTSTATUS)0xC0000155) /**< A requested type of logon (for example, interactive, network, and service) is not granted by the local security policy of the target system. Ask the system administrator to grant the necessary form of logon. */
#define STATUS_TOO_MANY_SECRETS                                            ((NTSTATUS)0xC0000156) /**< The maximum number of secrets that can be stored in a single system was exceeded. The length and number of secrets is limited to satisfy U.S. State Department export restrictions. */
#define STATUS_SECRET_TOO_LONG                                             ((NTSTATUS)0xC0000157) /**< The length of a secret exceeds the maximum allowable length. The length and number of secrets is limited to satisfy U.S. State Department export restrictions. */
#define STATUS_INTERNAL_DB_ERROR                                           ((NTSTATUS)0xC0000158) /**< The local security authority (LSA) database contains an internal inconsistency. */
#define STATUS_FULLSCREEN_MODE                                             ((NTSTATUS)0xC0000159) /**< The requested operation cannot be performed in full-screen mode. */
#define STATUS_TOO_MANY_CONTEXT_IDS                                        ((NTSTATUS)0xC000015A) /**< During a logon attempt, the user's security context accumulated too many security IDs. This is a very unusual situation. Remove the user from some global or local groups to reduce the number of security IDs to incorporate into the security context. */
#define STATUS_LOGON_TYPE_NOT_GRANTED                                      ((NTSTATUS)0xC000015B) /**< A user has requested a type of logon (for example, interactive or network) that has not been granted. An administrator has control over who can logon interactively and through the network. */
#define STATUS_NOT_REGISTRY_FILE                                           ((NTSTATUS)0xC000015C) /**< The system has attempted to load or restore a file into the registry, and the specified file is not in the format of a registry file. */
#define STATUS_NT_CROSS_ENCRYPTION_REQUIRED                                ((NTSTATUS)0xC000015D) /**< An attempt was made to change a user password in the security account manager without providing the necessary Windows cross-encrypted password. */
#define STATUS_DOMAIN_CTRLR_CONFIG_ERROR                                   ((NTSTATUS)0xC000015E) /**< A domain server has an incorrect configuration. */
#define STATUS_FT_MISSING_MEMBER                                           ((NTSTATUS)0xC000015F) /**< An attempt was made to explicitly access the secondary copy of information via a device control to the fault tolerance driver and the secondary copy is not present in the system. */
#define STATUS_ILL_FORMED_SERVICE_ENTRY                                    ((NTSTATUS)0xC0000160) /**< A configuration registry node that represents a driver service entry was ill-formed and did not contain the required value entries. */
#define STATUS_ILLEGAL_CHARACTER                                           ((NTSTATUS)0xC0000161) /**< An illegal character was encountered. For a multibyte character set, this includes a lead byte without a succeeding trail byte. For the Unicode character set this includes the characters 0xFFFF and 0xFFFE. */
#define STATUS_UNMAPPABLE_CHARACTER                                        ((NTSTATUS)0xC0000162) /**< No mapping for the Unicode character exists in the target multibyte code page. */
#define STATUS_UNDEFINED_CHARACTER                                         ((NTSTATUS)0xC0000163) /**< The Unicode character is not defined in the Unicode character set that is installed on the system. */
#define STATUS_FLOPPY_VOLUME                                               ((NTSTATUS)0xC0000164) /**< The paging file cannot be created on a floppy disk. */
#define STATUS_FLOPPY_ID_MARK_NOT_FOUND                                    ((NTSTATUS)0xC0000165) /**< {Floppy Disk Error} While accessing a floppy disk, an ID address mark was not found. */
#define STATUS_FLOPPY_WRONG_CYLINDER                                       ((NTSTATUS)0xC0000166) /**< {Floppy Disk Error} While accessing a floppy disk, the track address from the sector ID field was found to be different from the track address that is maintained by the controller. */
#define STATUS_FLOPPY_UNKNOWN_ERROR                                        ((NTSTATUS)0xC0000167) /**< {Floppy Disk Error} The floppy disk controller reported an error that is not recognized by the floppy disk driver. */
#define STATUS_FLOPPY_BAD_REGISTERS                                        ((NTSTATUS)0xC0000168) /**< {Floppy Disk Error} While accessing a floppy-disk, the controller returned inconsistent results via its registers. */
#define STATUS_DISK_RECALIBRATE_FAILED                                     ((NTSTATUS)0xC0000169) /**< {Hard Disk Error} While accessing the hard disk, a recalibrate operation failed, even after retries. */
#define STATUS_DISK_OPERATION_FAILED                                       ((NTSTATUS)0xC000016A) /**< {Hard Disk Error} While accessing the hard disk, a disk operation failed even after retries. */
#define STATUS_DISK_RESET_FAILED                                           ((NTSTATUS)0xC000016B) /**< {Hard Disk Error} While accessing the hard disk, a disk controller reset was needed, but even that failed. */
#define STATUS_SHARED_IRQ_BUSY                                             ((NTSTATUS)0xC000016C) /**< An attempt was made to open a device that was sharing an interrupt request (IRQ) with other devices. At least one other device that uses that IRQ was already opened. Two concurrent opens of devices that share an IRQ and only work via interrupts is not supported for the particular bus type that the devices use. */
#define STATUS_FT_ORPHANING                                                ((NTSTATUS)0xC000016D) /**< {FT Orphaning} A disk that is part of a fault-tolerant volume can no longer be accessed. */
#define STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT                            ((NTSTATUS)0xC000016E) /**< The basic input/output system (BIOS) failed to connect a system interrupt to the device or bus for which the device is connected. */
#define STATUS_PARTITION_FAILURE                                           ((NTSTATUS)0xC0000172) /**< The tape could not be partitioned. */
#define STATUS_INVALID_BLOCK_LENGTH                                        ((NTSTATUS)0xC0000173) /**< When accessing a new tape of a multi-volume partition, the current blocksize is incorrect. */
#define STATUS_DEVICE_NOT_PARTITIONED                                      ((NTSTATUS)0xC0000174) /**< The tape partition information could not be found when loading a tape. */
#define STATUS_UNABLE_TO_LOCK_MEDIA                                        ((NTSTATUS)0xC0000175) /**< An attempt to lock the eject media mechanism failed. */
#define STATUS_UNABLE_TO_UNLOAD_MEDIA                                      ((NTSTATUS)0xC0000176) /**< An attempt to unload media failed. */
#define STATUS_EOM_OVERFLOW                                                ((NTSTATUS)0xC0000177) /**< The physical end of tape was detected. */
#define STATUS_NO_MEDIA                                                    ((NTSTATUS)0xC0000178) /**< {No Media} There is no media in the drive. Insert media into drive %hs. */
#define STATUS_NO_SUCH_MEMBER                                              ((NTSTATUS)0xC000017A) /**< A member could not be added to or removed from the local group because the member does not exist. */
#define STATUS_INVALID_MEMBER                                              ((NTSTATUS)0xC000017B) /**< A new member could not be added to a local group because the member has the wrong account type. */
#define STATUS_KEY_DELETED                                                 ((NTSTATUS)0xC000017C) /**< An illegal operation was attempted on a registry key that has been marked for deletion. */
#define STATUS_NO_LOG_SPACE                                                ((NTSTATUS)0xC000017D) /**< The system could not allocate the required space in a registry log. */
#define STATUS_TOO_MANY_SIDS                                               ((NTSTATUS)0xC000017E) /**< Too many SIDs have been specified. */
#define STATUS_LM_CROSS_ENCRYPTION_REQUIRED                                ((NTSTATUS)0xC000017F) /**< An attempt was made to change a user password in the security account manager without providing the necessary LM cross-encrypted password. */
#define STATUS_KEY_HAS_CHILDREN                                            ((NTSTATUS)0xC0000180) /**< An attempt was made to create a symbolic link in a registry key that already has subkeys or values. */
#define STATUS_CHILD_MUST_BE_VOLATILE                                      ((NTSTATUS)0xC0000181) /**< An attempt was made to create a stable subkey under a volatile parent key. */
#define STATUS_DEVICE_CONFIGURATION_ERROR                                  ((NTSTATUS)0xC0000182) /**< The I/O device is configured incorrectly or the configuration parameters to the driver are incorrect. */
#define STATUS_DRIVER_INTERNAL_ERROR                                       ((NTSTATUS)0xC0000183) /**< An error was detected between two drivers or within an I/O driver. */
#define STATUS_INVALID_DEVICE_STATE                                        ((NTSTATUS)0xC0000184) /**< The device is not in a valid state to perform this request. */
#define STATUS_IO_DEVICE_ERROR                                             ((NTSTATUS)0xC0000185) /**< The I/O device reported an I/O error. */
#define STATUS_DEVICE_PROTOCOL_ERROR                                       ((NTSTATUS)0xC0000186) /**< A protocol error was detected between the driver and the device. */
#define STATUS_BACKUP_CONTROLLER                                           ((NTSTATUS)0xC0000187) /**< This operation is only allowed for the primary domain controller of the domain. */
#define STATUS_LOG_FILE_FULL                                               ((NTSTATUS)0xC0000188) /**< The log file space is insufficient to support this operation. */
#define STATUS_TOO_LATE                                                    ((NTSTATUS)0xC0000189) /**< A write operation was attempted to a volume after it was dismounted. */
#define STATUS_NO_TRUST_LSA_SECRET                                         ((NTSTATUS)0xC000018A) /**< The workstation does not have a trust secret for the primary domain in the local LSA database. */
#define STATUS_NO_TRUST_SAM_ACCOUNT                                        ((NTSTATUS)0xC000018B) /**< On applicable Windows Server releases, the SAM database does not have a computer account for this workstation trust relationship. */
#define STATUS_TRUSTED_DOMAIN_FAILURE                                      ((NTSTATUS)0xC000018C) /**< The logon request failed because the trust relationship between the primary domain and the trusted domain failed. */
#define STATUS_TRUSTED_RELATIONSHIP_FAILURE                                ((NTSTATUS)0xC000018D) /**< The logon request failed because the trust relationship between this workstation and the primary domain failed. */
#define STATUS_EVENTLOG_FILE_CORRUPT                                       ((NTSTATUS)0xC000018E) /**< The Eventlog log file is corrupt. */
#define STATUS_EVENTLOG_CANT_START                                         ((NTSTATUS)0xC000018F) /**< No Eventlog log file could be opened. The Eventlog service did not start. */
#define STATUS_TRUST_FAILURE                                               ((NTSTATUS)0xC0000190) /**< The network logon failed. This might be because the validation authority cannot be reached. */
#define STATUS_MUTANT_LIMIT_EXCEEDED                                       ((NTSTATUS)0xC0000191) /**< An attempt was made to acquire a mutant such that its maximum count would have been exceeded. */
#define STATUS_NETLOGON_NOT_STARTED                                        ((NTSTATUS)0xC0000192) /**< An attempt was made to logon, but the NetLogon service was not started. */
#define STATUS_ACCOUNT_EXPIRED                                             ((NTSTATUS)0xC0000193) /**< The user account has expired. */
#define STATUS_POSSIBLE_DEADLOCK                                           ((NTSTATUS)0xC0000194) /**< {EXCEPTION} Possible deadlock condition. */
#define STATUS_NETWORK_CREDENTIAL_CONFLICT                                 ((NTSTATUS)0xC0000195) /**< Multiple connections to a server or shared resource by the same user, using more than one user name, are not allowed. Disconnect all previous connections to the server or shared resource and try again. */
#define STATUS_REMOTE_SESSION_LIMIT                                        ((NTSTATUS)0xC0000196) /**< An attempt was made to establish a session to a network server, but there are already too many sessions established to that server. */
#define STATUS_EVENTLOG_FILE_CHANGED                                       ((NTSTATUS)0xC0000197) /**< The log file has changed between reads. */
#define STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT                           ((NTSTATUS)0xC0000198) /**< The account used is an interdomain trust account. Use your global user account or local user account to access this server. */
#define STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT                           ((NTSTATUS)0xC0000199) /**< The account used is a computer account. Use your global user account or local user account to access this server. */
#define STATUS_NOLOGON_SERVER_TRUST_ACCOUNT                                ((NTSTATUS)0xC000019A) /**< The account used is a server trust account. Use your global user account or local user account to access this server. */
#define STATUS_DOMAIN_TRUST_INCONSISTENT                                   ((NTSTATUS)0xC000019B) /**< The name or SID of the specified domain is inconsistent with the trust information for that domain. */
#define STATUS_FS_DRIVER_REQUIRED                                          ((NTSTATUS)0xC000019C) /**< A volume has been accessed for which a file system driver is required that has not yet been loaded. */
#define STATUS_IMAGE_ALREADY_LOADED_AS_DLL                                 ((NTSTATUS)0xC000019D) /**< Indicates that the specified image is already loaded as a DLL. */
#define STATUS_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING        ((NTSTATUS)0xC000019E) /**< Short name settings cannot be changed on this volume due to the global registry setting. */
#define STATUS_SHORT_NAMES_NOT_ENABLED_ON_VOLUME                           ((NTSTATUS)0xC000019F) /**< Short names are not enabled on this volume. */
#define STATUS_SECURITY_STREAM_IS_INCONSISTENT                             ((NTSTATUS)0xC00001A0) /**< The security stream for the given volume is in an inconsistent state. Please run CHKDSK on the volume. */
#define STATUS_INVALID_LOCK_RANGE                                          ((NTSTATUS)0xC00001A1) /**< A requested file lock operation cannot be processed due to an invalid byte range. */
#define STATUS_INVALID_ACE_CONDITION                                       ((NTSTATUS)0xC00001A2) /**< The specified access control entry (ACE) contains an invalid condition. */
#define STATUS_IMAGE_SUBSYSTEM_NOT_PRESENT                                 ((NTSTATUS)0xC00001A3) /**< The subsystem needed to support the image type is not present. */
#define STATUS_NOTIFICATION_GUID_ALREADY_DEFINED                           ((NTSTATUS)0xC00001A4) /**< The specified file already has a notification GUID associated with it. */
#define STATUS_NETWORK_OPEN_RESTRICTION                                    ((NTSTATUS)0xC0000201) /**< A remote open failed because the network open restrictions were not satisfied. */
#define STATUS_NO_USER_SESSION_KEY                                         ((NTSTATUS)0xC0000202) /**< There is no user session key for the specified logon session. */
#define STATUS_USER_SESSION_DELETED                                        ((NTSTATUS)0xC0000203) /**< The remote user session has been deleted. */
#define STATUS_RESOURCE_LANG_NOT_FOUND                                     ((NTSTATUS)0xC0000204) /**< Indicates the specified resource language ID cannot be found in the image file. */
#define STATUS_INSUFF_SERVER_RESOURCES                                     ((NTSTATUS)0xC0000205) /**< Insufficient server resources exist to complete the request. */
#define STATUS_INVALID_BUFFER_SIZE                                         ((NTSTATUS)0xC0000206) /**< The size of the buffer is invalid for the specified operation. */
#define STATUS_INVALID_ADDRESS_COMPONENT                                   ((NTSTATUS)0xC0000207) /**< The transport rejected the specified network address as invalid. */
#define STATUS_INVALID_ADDRESS_WILDCARD                                    ((NTSTATUS)0xC0000208) /**< The transport rejected the specified network address due to invalid use of a wildcard. */
#define STATUS_TOO_MANY_ADDRESSES                                          ((NTSTATUS)0xC0000209) /**< The transport address could not be opened because all the available addresses are in use. */
#define STATUS_ADDRESS_ALREADY_EXISTS                                      ((NTSTATUS)0xC000020A) /**< The transport address could not be opened because it already exists. */
#define STATUS_ADDRESS_CLOSED                                              ((NTSTATUS)0xC000020B) /**< The transport address is now closed. */
#define STATUS_CONNECTION_DISCONNECTED                                     ((NTSTATUS)0xC000020C) /**< The transport connection is now disconnected. */
#define STATUS_CONNECTION_RESET                                            ((NTSTATUS)0xC000020D) /**< The transport connection has been reset. */
#define STATUS_TOO_MANY_NODES                                              ((NTSTATUS)0xC000020E) /**< The transport cannot dynamically acquire any more nodes. */
#define STATUS_TRANSACTION_ABORTED                                         ((NTSTATUS)0xC000020F) /**< The transport aborted a pending transaction. */
#define STATUS_TRANSACTION_TIMED_OUT                                       ((NTSTATUS)0xC0000210) /**< The transport timed out a request that is waiting for a response. */
#define STATUS_TRANSACTION_NO_RELEASE                                      ((NTSTATUS)0xC0000211) /**< The transport did not receive a release for a pending response. */
#define STATUS_TRANSACTION_NO_MATCH                                        ((NTSTATUS)0xC0000212) /**< The transport did not find a transaction that matches the specific token. */
#define STATUS_TRANSACTION_RESPONDED                                       ((NTSTATUS)0xC0000213) /**< The transport had previously responded to a transaction request. */
#define STATUS_TRANSACTION_INVALID_ID                                      ((NTSTATUS)0xC0000214) /**< The transport does not recognize the specified transaction request ID. */
#define STATUS_TRANSACTION_INVALID_TYPE                                    ((NTSTATUS)0xC0000215) /**< The transport does not recognize the specified transaction request type. */
#define STATUS_NOT_SERVER_SESSION                                          ((NTSTATUS)0xC0000216) /**< The transport can only process the specified request on the server side of a session. */
#define STATUS_NOT_CLIENT_SESSION                                          ((NTSTATUS)0xC0000217) /**< The transport can only process the specified request on the client side of a session. */
#define STATUS_CANNOT_LOAD_REGISTRY_FILE                                   ((NTSTATUS)0xC0000218) /**< {Registry File Failure} The registry cannot load the hive (file): %hs or its log or alternate. It is corrupt, absent, or not writable. */
#define STATUS_DEBUG_ATTACH_FAILED                                         ((NTSTATUS)0xC0000219) /**< {Unexpected Failure in DebugActiveProcess} An unexpected failure occurred while processing a DebugActiveProcess API request. Choosing OK will terminate the process, and choosing Cancel will ignore the error. */
#define STATUS_SYSTEM_PROCESS_TERMINATED                                   ((NTSTATUS)0xC000021A) /**< {Fatal System Error} The %hs system process terminated unexpectedly with a status of 0x%08x (0x%08x 0x%08x). The system has been shut down. */
#define STATUS_DATA_NOT_ACCEPTED                                           ((NTSTATUS)0xC000021B) /**< {Data Not Accepted} The TDI client could not handle the data received during an indication. */
#define STATUS_NO_BROWSER_SERVERS_FOUND                                    ((NTSTATUS)0xC000021C) /**< {Unable to Retrieve Browser Server List} The list of servers for this workgroup is not currently available. */
#define STATUS_VDM_HARD_ERROR                                              ((NTSTATUS)0xC000021D) /**< NTVDM encountered a hard error. */
#define STATUS_DRIVER_CANCEL_TIMEOUT                                       ((NTSTATUS)0xC000021E) /**< {Cancel Timeout} The driver %hs failed to complete a canceled I/O request in the allotted time. */
#define STATUS_REPLY_MESSAGE_MISMATCH                                      ((NTSTATUS)0xC000021F) /**< {Reply Message Mismatch} An attempt was made to reply to an LPC message, but the thread specified by the client ID in the message was not waiting on that message. */
#define STATUS_MAPPED_ALIGNMENT                                            ((NTSTATUS)0xC0000220) /**< {Mapped View Alignment Incorrect} An attempt was made to map a view of a file, but either the specified base address or the offset into the file were not aligned on the proper allocation granularity. */
#define STATUS_IMAGE_CHECKSUM_MISMATCH                                     ((NTSTATUS)0xC0000221) /**< {Bad Image Checksum} The image %hs is possibly corrupt. The header checksum does not match the computed checksum. */
#define STATUS_LOST_WRITEBEHIND_DATA                                       ((NTSTATUS)0xC0000222) /**< {Delayed Write Failed} Windows was unable to save all the data for the file %hs. The data has been lost. This error might be caused by a failure of your computer hardware or network connection. Try to save this file elsewhere. */
#define STATUS_CLIENT_SERVER_PARAMETERS_INVALID                            ((NTSTATUS)0xC0000223) /**< The parameters passed to the server in the client/server shared memory window were invalid. Too much data might have been put in the shared memory window. */
#define STATUS_PASSWORD_MUST_CHANGE                                        ((NTSTATUS)0xC0000224) /**< The user password must be changed before logging on the first time. */
#define STATUS_NOT_FOUND                                                   ((NTSTATUS)0xC0000225) /**< The object was not found. */
#define STATUS_NOT_TINY_STREAM                                             ((NTSTATUS)0xC0000226) /**< The stream is not a tiny stream. */
#define STATUS_RECOVERY_FAILURE                                            ((NTSTATUS)0xC0000227) /**< A transaction recovery failed. */
#define STATUS_STACK_OVERFLOW_READ                                         ((NTSTATUS)0xC0000228) /**< The request must be handled by the stack overflow code. */
#define STATUS_FAIL_CHECK                                                  ((NTSTATUS)0xC0000229) /**< A consistency check failed. */
#define STATUS_DUPLICATE_OBJECTID                                          ((NTSTATUS)0xC000022A) /**< The attempt to insert the ID in the index failed because the ID is already in the index. */
#define STATUS_OBJECTID_EXISTS                                             ((NTSTATUS)0xC000022B) /**< The attempt to set the object ID failed because the object already has an ID. */
#define STATUS_CONVERT_TO_LARGE                                            ((NTSTATUS)0xC000022C) /**< Internal OFS status codes indicating how an allocation operation is handled. Either it is retried after the containing oNode is moved or the extent stream is converted to a large stream. */
#define STATUS_RETRY                                                       ((NTSTATUS)0xC000022D) /**< The request needs to be retried. */
#define STATUS_FOUND_OUT_OF_SCOPE                                          ((NTSTATUS)0xC000022E) /**< The attempt to find the object found an object on the volume that matches by ID; however, it is out of the scope of the handle that is used for the operation. */
#define STATUS_ALLOCATE_BUCKET                                             ((NTSTATUS)0xC000022F) /**< The bucket array must be grown. Retry the transaction after doing so. */
#define STATUS_PROPSET_NOT_FOUND                                           ((NTSTATUS)0xC0000230) /**< The specified property set does not exist on the object. */
#define STATUS_MARSHALL_OVERFLOW                                           ((NTSTATUS)0xC0000231) /**< The user/kernel marshaling buffer has overflowed. */
#define STATUS_INVALID_VARIANT                                             ((NTSTATUS)0xC0000232) /**< The supplied variant structure contains invalid data. */
#define STATUS_DOMAIN_CONTROLLER_NOT_FOUND                                 ((NTSTATUS)0xC0000233) /**< A domain controller for this domain was not found. */
#define STATUS_ACCOUNT_LOCKED_OUT                                          ((NTSTATUS)0xC0000234) /**< The user account has been automatically locked because too many invalid logon attempts or password change attempts have been requested. */
#define STATUS_HANDLE_NOT_CLOSABLE                                         ((NTSTATUS)0xC0000235) /**< NtClose was called on a handle that was protected from close via NtSetInformationObject. */
#define STATUS_CONNECTION_REFUSED                                          ((NTSTATUS)0xC0000236) /**< The transport-connection attempt was refused by the remote system. */
#define STATUS_GRACEFUL_DISCONNECT                                         ((NTSTATUS)0xC0000237) /**< The transport connection was gracefully closed. */
#define STATUS_ADDRESS_ALREADY_ASSOCIATED                                  ((NTSTATUS)0xC0000238) /**< The transport endpoint already has an address associated with it. */
#define STATUS_ADDRESS_NOT_ASSOCIATED                                      ((NTSTATUS)0xC0000239) /**< An address has not yet been associated with the transport endpoint. */
#define STATUS_CONNECTION_INVALID                                          ((NTSTATUS)0xC000023A) /**< An operation was attempted on a nonexistent transport connection. */
#define STATUS_CONNECTION_ACTIVE                                           ((NTSTATUS)0xC000023B) /**< An invalid operation was attempted on an active transport connection. */
#define STATUS_NETWORK_UNREACHABLE                                         ((NTSTATUS)0xC000023C) /**< The remote network is not reachable by the transport. */
#define STATUS_HOST_UNREACHABLE                                            ((NTSTATUS)0xC000023D) /**< The remote system is not reachable by the transport. */
#define STATUS_PROTOCOL_UNREACHABLE                                        ((NTSTATUS)0xC000023E) /**< The remote system does not support the transport protocol. */
#define STATUS_PORT_UNREACHABLE                                            ((NTSTATUS)0xC000023F) /**< No service is operating at the destination port of the transport on the remote system. */
#define STATUS_REQUEST_ABORTED                                             ((NTSTATUS)0xC0000240) /**< The request was aborted. */
#define STATUS_CONNECTION_ABORTED                                          ((NTSTATUS)0xC0000241) /**< The transport connection was aborted by the local system. */
#define STATUS_BAD_COMPRESSION_BUFFER                                      ((NTSTATUS)0xC0000242) /**< The specified buffer contains ill-formed data. */
#define STATUS_USER_MAPPED_FILE                                            ((NTSTATUS)0xC0000243) /**< The requested operation cannot be performed on a file with a user mapped section open. */
#define STATUS_AUDIT_FAILED                                                ((NTSTATUS)0xC0000244) /**< {Audit Failed} An attempt to generate a security audit failed. */
#define STATUS_TIMER_RESOLUTION_NOT_SET                                    ((NTSTATUS)0xC0000245) /**< The timer resolution was not previously set by the current process. */
#define STATUS_CONNECTION_COUNT_LIMIT                                      ((NTSTATUS)0xC0000246) /**< A connection to the server could not be made because the limit on the number of concurrent connections for this account has been reached. */
#define STATUS_LOGIN_TIME_RESTRICTION                                      ((NTSTATUS)0xC0000247) /**< Attempting to log on during an unauthorized time of day for this account. */
#define STATUS_LOGIN_WKSTA_RESTRICTION                                     ((NTSTATUS)0xC0000248) /**< The account is not authorized to log on from this station. */
#define STATUS_IMAGE_MP_UP_MISMATCH                                        ((NTSTATUS)0xC0000249) /**< {UP/MP Image Mismatch} The image %hs has been modified for use on a uniprocessor system, but you are running it on a multiprocessor machine. Reinstall the image file. */
#define STATUS_INSUFFICIENT_LOGON_INFO                                     ((NTSTATUS)0xC0000250) /**< There is insufficient account information to log you on. */
#define STATUS_BAD_DLL_ENTRYPOINT                                          ((NTSTATUS)0xC0000251) /**< {Invalid DLL Entrypoint} The dynamic link library %hs is not written correctly. The stack pointer has been left in an inconsistent state. The entry point should be declared as WINAPI or STDCALL. Select YES to fail the DLL load. Select NO to continue execution. Selecting NO might cause the application to operate incorrectly. */
#define STATUS_BAD_SERVICE_ENTRYPOINT                                      ((NTSTATUS)0xC0000252) /**< {Invalid Service Callback Entrypoint} The %hs service is not written correctly. The stack pointer has been left in an inconsistent state. The callback entry point should be declared as WINAPI or STDCALL. Selecting OK will cause the service to continue operation. However, the service process might operate incorrectly. */
#define STATUS_LPC_REPLY_LOST                                              ((NTSTATUS)0xC0000253) /**< The server received the messages but did not send a reply. */
#define STATUS_IP_ADDRESS_CONFLICT1                                        ((NTSTATUS)0xC0000254) /**< There is an IP address conflict with another system on the network. */
#define STATUS_IP_ADDRESS_CONFLICT2                                        ((NTSTATUS)0xC0000255) /**< There is an IP address conflict with another system on the network. */
#define STATUS_REGISTRY_QUOTA_LIMIT                                        ((NTSTATUS)0xC0000256) /**< {Low On Registry Space} The system has reached the maximum size that is allowed for the system part of the registry. Additional storage requests will be ignored. */
#define STATUS_PATH_NOT_COVERED                                            ((NTSTATUS)0xC0000257) /**< The contacted server does not support the indicated part of the DFS namespace. */
#define STATUS_NO_CALLBACK_ACTIVE                                          ((NTSTATUS)0xC0000258) /**< A callback return system service cannot be executed when no callback is active. */
#define STATUS_LICENSE_QUOTA_EXCEEDED                                      ((NTSTATUS)0xC0000259) /**< The service being accessed is licensed for a particular number of connections. No more connections can be made to the service at this time because the service has already accepted the maximum number of connections. */
#define STATUS_PWD_TOO_SHORT                                               ((NTSTATUS)0xC000025A) /**< The password provided is too short to meet the policy of your user account. Choose a longer password. */
#define STATUS_PWD_TOO_RECENT                                              ((NTSTATUS)0xC000025B) /**< The policy of your user account does not allow you to change passwords too frequently. This is done to prevent users from changing back to a familiar, but potentially discovered, password. If you feel your password has been compromised, contact your administrator immediately to have a new one assigned. */
#define STATUS_PWD_HISTORY_CONFLICT                                        ((NTSTATUS)0xC000025C) /**< You have attempted to change your password to one that you have used in the past. The policy of your user account does not allow this. Select a password that you have not previously used. */
#define STATUS_PLUGPLAY_NO_DEVICE                                          ((NTSTATUS)0xC000025E) /**< You have attempted to load a legacy device driver while its device instance had been disabled. */
#define STATUS_UNSUPPORTED_COMPRESSION                                     ((NTSTATUS)0xC000025F) /**< The specified compression format is unsupported. */
#define STATUS_INVALID_HW_PROFILE                                          ((NTSTATUS)0xC0000260) /**< The specified hardware profile configuration is invalid. */
#define STATUS_INVALID_PLUGPLAY_DEVICE_PATH                                ((NTSTATUS)0xC0000261) /**< The specified Plug and Play registry device path is invalid. */
#define STATUS_DRIVER_ORDINAL_NOT_FOUND                                    ((NTSTATUS)0xC0000262) /**< {Driver Entry Point Not Found} The %hs device driver could not locate the ordinal %ld in driver %hs. */
#define STATUS_DRIVER_ENTRYPOINT_NOT_FOUND                                 ((NTSTATUS)0xC0000263) /**< {Driver Entry Point Not Found} The %hs device driver could not locate the entry point %hs in driver %hs. */
#define STATUS_RESOURCE_NOT_OWNED                                          ((NTSTATUS)0xC0000264) /**< {Application Error} The application attempted to release a resource it did not own. Click OK to terminate the application. */
#define STATUS_TOO_MANY_LINKS                                              ((NTSTATUS)0xC0000265) /**< An attempt was made to create more links on a file than the file system supports. */
#define STATUS_QUOTA_LIST_INCONSISTENT                                     ((NTSTATUS)0xC0000266) /**< The specified quota list is internally inconsistent with its descriptor. */
#define STATUS_FILE_IS_OFFLINE                                             ((NTSTATUS)0xC0000267) /**< The specified file has been relocated to offline storage. */
#define STATUS_EVALUATION_EXPIRATION                                       ((NTSTATUS)0xC0000268) /**< {Windows Evaluation Notification} The evaluation period for this installation of Windows has expired. This system will shutdown in 1 hour. To restore access to this installation of Windows, upgrade this installation by using a licensed distribution of this product. */
#define STATUS_ILLEGAL_DLL_RELOCATION                                      ((NTSTATUS)0xC0000269) /**< {Illegal System DLL Relocation} The system DLL %hs was relocated in memory. The application will not run properly. The relocation occurred because the DLL %hs occupied an address range that is reserved for Windows system DLLs. The vendor supplying the DLL should be contacted for a new DLL. */
#define STATUS_LICENSE_VIOLATION                                           ((NTSTATUS)0xC000026A) /**< {License Violation} The system has detected tampering with your registered product type. This is a violation of your software license. Tampering with the product type is not permitted. */
#define STATUS_DLL_INIT_FAILED_LOGOFF                                      ((NTSTATUS)0xC000026B) /**< {DLL Initialization Failed} The application failed to initialize because the window station is shutting down. */
#define STATUS_DRIVER_UNABLE_TO_LOAD                                       ((NTSTATUS)0xC000026C) /**< {Unable to Load Device Driver} %hs device driver could not be loaded. Error Status was 0x%x. */
#define STATUS_DFS_UNAVAILABLE                                             ((NTSTATUS)0xC000026D) /**< DFS is unavailable on the contacted server. */
#define STATUS_VOLUME_DISMOUNTED                                           ((NTSTATUS)0xC000026E) /**< An operation was attempted to a volume after it was dismounted. */
#define STATUS_WX86_INTERNAL_ERROR                                         ((NTSTATUS)0xC000026F) /**< An internal error occurred in the Win32 x86 emulation subsystem. */
#define STATUS_WX86_FLOAT_STACK_CHECK                                      ((NTSTATUS)0xC0000270) /**< Win32 x86 emulation subsystem floating-point stack check. */
#define STATUS_VALIDATE_CONTINUE                                           ((NTSTATUS)0xC0000271) /**< The validation process needs to continue on to the next step. */
#define STATUS_NO_MATCH                                                    ((NTSTATUS)0xC0000272) /**< There was no match for the specified key in the index. */
#define STATUS_NO_MORE_MATCHES                                             ((NTSTATUS)0xC0000273) /**< There are no more matches for the current index enumeration. */
#define STATUS_NOT_A_REPARSE_POINT                                         ((NTSTATUS)0xC0000275) /**< The NTFS file or directory is not a reparse point. */
#define STATUS_IO_REPARSE_TAG_INVALID                                      ((NTSTATUS)0xC0000276) /**< The Windows I/O reparse tag passed for the NTFS reparse point is invalid. */
#define STATUS_IO_REPARSE_TAG_MISMATCH                                     ((NTSTATUS)0xC0000277) /**< The Windows I/O reparse tag does not match the one that is in the NTFS reparse point. */
#define STATUS_IO_REPARSE_DATA_INVALID                                     ((NTSTATUS)0xC0000278) /**< The user data passed for the NTFS reparse point is invalid. */
#define STATUS_IO_REPARSE_TAG_NOT_HANDLED                                  ((NTSTATUS)0xC0000279) /**< The layered file system driver for this I/O tag did not handle it when needed. */
#define STATUS_REPARSE_POINT_NOT_RESOLVED                                  ((NTSTATUS)0xC0000280) /**< The NTFS symbolic link could not be resolved even though the initial file name is valid. */
#define STATUS_DIRECTORY_IS_A_REPARSE_POINT                                ((NTSTATUS)0xC0000281) /**< The NTFS directory is a reparse point. */
#define STATUS_RANGE_LIST_CONFLICT                                         ((NTSTATUS)0xC0000282) /**< The range could not be added to the range list because of a conflict. */
#define STATUS_SOURCE_ELEMENT_EMPTY                                        ((NTSTATUS)0xC0000283) /**< The specified medium changer source element contains no media. */
#define STATUS_DESTINATION_ELEMENT_FULL                                    ((NTSTATUS)0xC0000284) /**< The specified medium changer destination element already contains media. */
#define STATUS_ILLEGAL_ELEMENT_ADDRESS                                     ((NTSTATUS)0xC0000285) /**< The specified medium changer element does not exist. */
#define STATUS_MAGAZINE_NOT_PRESENT                                        ((NTSTATUS)0xC0000286) /**< The specified element is contained in a magazine that is no longer present. */
#define STATUS_REINITIALIZATION_NEEDED                                     ((NTSTATUS)0xC0000287) /**< The device requires re-initialization due to hardware errors. */
#define STATUS_ENCRYPTION_FAILED                                           ((NTSTATUS)0xC000028A) /**< The file encryption attempt failed. */
#define STATUS_DECRYPTION_FAILED                                           ((NTSTATUS)0xC000028B) /**< The file decryption attempt failed. */
#define STATUS_RANGE_NOT_FOUND                                             ((NTSTATUS)0xC000028C) /**< The specified range could not be found in the range list. */
#define STATUS_NO_RECOVERY_POLICY                                          ((NTSTATUS)0xC000028D) /**< There is no encryption recovery policy configured for this system. */
#define STATUS_NO_EFS                                                      ((NTSTATUS)0xC000028E) /**< The required encryption driver is not loaded for this system. */
#define STATUS_WRONG_EFS                                                   ((NTSTATUS)0xC000028F) /**< The file was encrypted with a different encryption driver than is currently loaded. */
#define STATUS_NO_USER_KEYS                                                ((NTSTATUS)0xC0000290) /**< There are no EFS keys defined for the user. */
#define STATUS_FILE_NOT_ENCRYPTED                                          ((NTSTATUS)0xC0000291) /**< The specified file is not encrypted. */
#define STATUS_NOT_EXPORT_FORMAT                                           ((NTSTATUS)0xC0000292) /**< The specified file is not in the defined EFS export format. */
#define STATUS_FILE_ENCRYPTED                                              ((NTSTATUS)0xC0000293) /**< The specified file is encrypted and the user does not have the ability to decrypt it. */
#define STATUS_WMI_GUID_NOT_FOUND                                          ((NTSTATUS)0xC0000295) /**< The GUID passed was not recognized as valid by a WMI data provider. */
#define STATUS_WMI_INSTANCE_NOT_FOUND                                      ((NTSTATUS)0xC0000296) /**< The instance name passed was not recognized as valid by a WMI data provider. */
#define STATUS_WMI_ITEMID_NOT_FOUND                                        ((NTSTATUS)0xC0000297) /**< The data item ID passed was not recognized as valid by a WMI data provider. */
#define STATUS_WMI_TRY_AGAIN                                               ((NTSTATUS)0xC0000298) /**< The WMI request could not be completed and should be retried. */
#define STATUS_SHARED_POLICY                                               ((NTSTATUS)0xC0000299) /**< The policy object is shared and can only be modified at the root. */
#define STATUS_POLICY_OBJECT_NOT_FOUND                                     ((NTSTATUS)0xC000029A) /**< The policy object does not exist when it should. */
#define STATUS_POLICY_ONLY_IN_DS                                           ((NTSTATUS)0xC000029B) /**< The requested policy information only lives in the Ds. */
#define STATUS_VOLUME_NOT_UPGRADED                                         ((NTSTATUS)0xC000029C) /**< The volume must be upgraded to enable this feature. */
#define STATUS_REMOTE_STORAGE_NOT_ACTIVE                                   ((NTSTATUS)0xC000029D) /**< The remote storage service is not operational at this time. */
#define STATUS_REMOTE_STORAGE_MEDIA_ERROR                                  ((NTSTATUS)0xC000029E) /**< The remote storage service encountered a media error. */
#define STATUS_NO_TRACKING_SERVICE                                         ((NTSTATUS)0xC000029F) /**< The tracking (workstation) service is not running. */
#define STATUS_SERVER_SID_MISMATCH                                         ((NTSTATUS)0xC00002A0) /**< The server process is running under a SID that is different from the SID that is required by client. */
#define STATUS_DS_NO_ATTRIBUTE_OR_VALUE                                    ((NTSTATUS)0xC00002A1) /**< The specified directory service attribute or value does not exist. */
#define STATUS_DS_INVALID_ATTRIBUTE_SYNTAX                                 ((NTSTATUS)0xC00002A2) /**< The attribute syntax specified to the directory service is invalid. */
#define STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED                                 ((NTSTATUS)0xC00002A3) /**< The attribute type specified to the directory service is not defined. */
#define STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS                                ((NTSTATUS)0xC00002A4) /**< The specified directory service attribute or value already exists. */
#define STATUS_DS_BUSY                                                     ((NTSTATUS)0xC00002A5) /**< The directory service is busy. */
#define STATUS_DS_UNAVAILABLE                                              ((NTSTATUS)0xC00002A6) /**< The directory service is unavailable. */
#define STATUS_DS_NO_RIDS_ALLOCATED                                        ((NTSTATUS)0xC00002A7) /**< The directory service was unable to allocate a relative identifier. */
#define STATUS_DS_NO_MORE_RIDS                                             ((NTSTATUS)0xC00002A8) /**< The directory service has exhausted the pool of relative identifiers. */
#define STATUS_DS_INCORRECT_ROLE_OWNER                                     ((NTSTATUS)0xC00002A9) /**< The requested operation could not be performed because the directory service is not the master for that type of operation. */
#define STATUS_DS_RIDMGR_INIT_ERROR                                        ((NTSTATUS)0xC00002AA) /**< The directory service was unable to initialize the subsystem that allocates relative identifiers. */
#define STATUS_DS_OBJ_CLASS_VIOLATION                                      ((NTSTATUS)0xC00002AB) /**< The requested operation did not satisfy one or more constraints that are associated with the class of the object. */
#define STATUS_DS_CANT_ON_NON_LEAF                                         ((NTSTATUS)0xC00002AC) /**< The directory service can perform the requested operation only on a leaf object. */
#define STATUS_DS_CANT_ON_RDN                                              ((NTSTATUS)0xC00002AD) /**< The directory service cannot perform the requested operation on the Relatively Defined Name (RDN) attribute of an object. */
#define STATUS_DS_CANT_MOD_OBJ_CLASS                                       ((NTSTATUS)0xC00002AE) /**< The directory service detected an attempt to modify the object class of an object. */
#define STATUS_DS_CROSS_DOM_MOVE_FAILED                                    ((NTSTATUS)0xC00002AF) /**< An error occurred while performing a cross domain move operation. */
#define STATUS_DS_GC_NOT_AVAILABLE                                         ((NTSTATUS)0xC00002B0) /**< Unable to contact the global catalog server. */
#define STATUS_DIRECTORY_SERVICE_REQUIRED                                  ((NTSTATUS)0xC00002B1) /**< The requested operation requires a directory service, and none was available. */
#define STATUS_REPARSE_ATTRIBUTE_CONFLICT                                  ((NTSTATUS)0xC00002B2) /**< The reparse attribute cannot be set because it is incompatible with an existing attribute. */
#define STATUS_CANT_ENABLE_DENY_ONLY                                       ((NTSTATUS)0xC00002B3) /**< A group marked "use for deny only" cannot be enabled. */
#define STATUS_FLOAT_MULTIPLE_FAULTS                                       ((NTSTATUS)0xC00002B4) /**< {EXCEPTION} Multiple floating-point faults. */
#define STATUS_FLOAT_MULTIPLE_TRAPS                                        ((NTSTATUS)0xC00002B5) /**< {EXCEPTION} Multiple floating-point traps. */
#define STATUS_DEVICE_REMOVED                                              ((NTSTATUS)0xC00002B6) /**< The device has been removed. */
#define STATUS_JOURNAL_DELETE_IN_PROGRESS                                  ((NTSTATUS)0xC00002B7) /**< The volume change journal is being deleted. */
#define STATUS_JOURNAL_NOT_ACTIVE                                          ((NTSTATUS)0xC00002B8) /**< The volume change journal is not active. */
#define STATUS_NOINTERFACE                                                 ((NTSTATUS)0xC00002B9) /**< The requested interface is not supported. */
#define STATUS_DS_ADMIN_LIMIT_EXCEEDED                                     ((NTSTATUS)0xC00002C1) /**< A directory service resource limit has been exceeded. */
#define STATUS_DRIVER_FAILED_SLEEP                                         ((NTSTATUS)0xC00002C2) /**< {System Standby Failed} The driver %hs does not support standby mode. Updating this driver allows the system to go to standby mode. */
#define STATUS_MUTUAL_AUTHENTICATION_FAILED                                ((NTSTATUS)0xC00002C3) /**< Mutual Authentication failed. The server password is out of date at the domain controller. */
#define STATUS_CORRUPT_SYSTEM_FILE                                         ((NTSTATUS)0xC00002C4) /**< The system file %1 has become corrupt and has been replaced. */
#define STATUS_DATATYPE_MISALIGNMENT_ERROR                                 ((NTSTATUS)0xC00002C5) /**< {EXCEPTION} Alignment Error A data type misalignment error was detected in a load or store instruction. */
#define STATUS_WMI_READ_ONLY                                               ((NTSTATUS)0xC00002C6) /**< The WMI data item or data block is read-only. */
#define STATUS_WMI_SET_FAILURE                                             ((NTSTATUS)0xC00002C7) /**< The WMI data item or data block could not be changed. */
#define STATUS_COMMITMENT_MINIMUM                                          ((NTSTATUS)0xC00002C8) /**< {Virtual Memory Minimum Too Low} Your system is low on virtual memory. Windows is increasing the size of your virtual memory paging file. During this process, memory requests for some applications might be denied. For more information, see Help. */
#define STATUS_REG_NAT_CONSUMPTION                                         ((NTSTATUS)0xC00002C9) /**< {EXCEPTION} Register NaT consumption faults. A NaT value is consumed on a non-speculative instruction. */
#define STATUS_TRANSPORT_FULL                                              ((NTSTATUS)0xC00002CA) /**< The transport element of the medium changer contains media, which is causing the operation to fail. */
#define STATUS_DS_SAM_INIT_FAILURE                                         ((NTSTATUS)0xC00002CB) /**< Security Accounts Manager initialization failed because of the following error: %hs Error Status: 0x%x. Click OK to shut down this system and restart in Directory Services Restore Mode. Check the event log for more detailed information. */
#define STATUS_ONLY_IF_CONNECTED                                           ((NTSTATUS)0xC00002CC) /**< This operation is supported only when you are connected to the server. */
#define STATUS_DS_SENSITIVE_GROUP_VIOLATION                                ((NTSTATUS)0xC00002CD) /**< Only an administrator can modify the membership list of an administrative group. */
#define STATUS_PNP_RESTART_ENUMERATION                                     ((NTSTATUS)0xC00002CE) /**< A device was removed so enumeration must be restarted. */
#define STATUS_JOURNAL_ENTRY_DELETED                                       ((NTSTATUS)0xC00002CF) /**< The journal entry has been deleted from the journal. */
#define STATUS_DS_CANT_MOD_PRIMARYGROUPID                                  ((NTSTATUS)0xC00002D0) /**< Cannot change the primary group ID of a domain controller account. */
#define STATUS_SYSTEM_IMAGE_BAD_SIGNATURE                                  ((NTSTATUS)0xC00002D1) /**< {Fatal System Error} The system image %s is not properly signed. The file has been replaced with the signed file. The system has been shut down. */
#define STATUS_PNP_REBOOT_REQUIRED                                         ((NTSTATUS)0xC00002D2) /**< The device will not start without a reboot. */
#define STATUS_POWER_STATE_INVALID                                         ((NTSTATUS)0xC00002D3) /**< The power state of the current device cannot support this request. */
#define STATUS_DS_INVALID_GROUP_TYPE                                       ((NTSTATUS)0xC00002D4) /**< The specified group type is invalid. */
#define STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN                       ((NTSTATUS)0xC00002D5) /**< In a mixed domain, no nesting of a global group if the group is security enabled. */
#define STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN                        ((NTSTATUS)0xC00002D6) /**< In a mixed domain, cannot nest local groups with other local groups, if the group is security enabled. */
#define STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER                            ((NTSTATUS)0xC00002D7) /**< A global group cannot have a local group as a member. */
#define STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER                        ((NTSTATUS)0xC00002D8) /**< A global group cannot have a universal group as a member. */
#define STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER                         ((NTSTATUS)0xC00002D9) /**< A universal group cannot have a local group as a member. */
#define STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER                      ((NTSTATUS)0xC00002DA) /**< A global group cannot have a cross-domain member. */
#define STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER                 ((NTSTATUS)0xC00002DB) /**< A local group cannot have another cross-domain local group as a member. */
#define STATUS_DS_HAVE_PRIMARY_MEMBERS                                     ((NTSTATUS)0xC00002DC) /**< Cannot change to a security-disabled group because primary members are in this group. */
#define STATUS_WMI_NOT_SUPPORTED                                           ((NTSTATUS)0xC00002DD) /**< The WMI operation is not supported by the data block or method. */
#define STATUS_INSUFFICIENT_POWER                                          ((NTSTATUS)0xC00002DE) /**< There is not enough power to complete the requested operation. */
#define STATUS_SAM_NEED_BOOTKEY_PASSWORD                                   ((NTSTATUS)0xC00002DF) /**< The Security Accounts Manager needs to get the boot password. */
#define STATUS_SAM_NEED_BOOTKEY_FLOPPY                                     ((NTSTATUS)0xC00002E0) /**< The Security Accounts Manager needs to get the boot key from the floppy disk. */
#define STATUS_DS_CANT_START                                               ((NTSTATUS)0xC00002E1) /**< The directory service cannot start. */
#define STATUS_DS_INIT_FAILURE                                             ((NTSTATUS)0xC00002E2) /**< The directory service could not start because of the following error: %hs Error Status: 0x%x. Click OK to shut down this system and restart in Directory Services Restore Mode. Check the event log for more detailed information. */
#define STATUS_SAM_INIT_FAILURE                                            ((NTSTATUS)0xC00002E3) /**< The Security Accounts Manager initialization failed because of the following error: %hs Error Status: 0x%x. Click OK to shut down this system and restart in Safe Mode. Check the event log for more detailed information. */
#define STATUS_DS_GC_REQUIRED                                              ((NTSTATUS)0xC00002E4) /**< The requested operation can be performed only on a global catalog server. */
#define STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY                               ((NTSTATUS)0xC00002E5) /**< A local group can only be a member of other local groups in the same domain. */
#define STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS                               ((NTSTATUS)0xC00002E6) /**< Foreign security principals cannot be members of universal groups. */
#define STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED                           ((NTSTATUS)0xC00002E7) /**< Your computer could not be joined to the domain. You have exceeded the maximum number of computer accounts you are allowed to create in this domain. Contact your system administrator to have this limit reset or increased. */
#define STATUS_CURRENT_DOMAIN_NOT_ALLOWED                                  ((NTSTATUS)0xC00002E9) /**< This operation cannot be performed on the current domain. */
#define STATUS_CANNOT_MAKE                                                 ((NTSTATUS)0xC00002EA) /**< The directory or file cannot be created. */
#define STATUS_SYSTEM_SHUTDOWN                                             ((NTSTATUS)0xC00002EB) /**< The system is in the process of shutting down. */
#define STATUS_DS_INIT_FAILURE_CONSOLE                                     ((NTSTATUS)0xC00002EC) /**< Directory Services could not start because of the following error: %hs Error Status: 0x%x. Click OK to shut down the system. You can use the recovery console to diagnose the system further. */
#define STATUS_DS_SAM_INIT_FAILURE_CONSOLE                                 ((NTSTATUS)0xC00002ED) /**< Security Accounts Manager initialization failed because of the following error: %hs Error Status: 0x%x. Click OK to shut down the system. You can use the recovery console to diagnose the system further. */
#define STATUS_UNFINISHED_CONTEXT_DELETED                                  ((NTSTATUS)0xC00002EE) /**< A security context was deleted before the context was completed. This is considered a logon failure. */
#define STATUS_NO_TGT_REPLY                                                ((NTSTATUS)0xC00002EF) /**< The client is trying to negotiate a context and the server requires user-to-user but did not send a TGT reply. */
#define STATUS_OBJECTID_NOT_FOUND                                          ((NTSTATUS)0xC00002F0) /**< An object ID was not found in the file. */
#define STATUS_NO_IP_ADDRESSES                                             ((NTSTATUS)0xC00002F1) /**< Unable to accomplish the requested task because the local machine does not have any IP addresses. */
#define STATUS_WRONG_CREDENTIAL_HANDLE                                     ((NTSTATUS)0xC00002F2) /**< The supplied credential handle does not match the credential that is associated with the security context. */
#define STATUS_CRYPTO_SYSTEM_INVALID                                       ((NTSTATUS)0xC00002F3) /**< The crypto system or checksum function is invalid because a required function is unavailable. */
#define STATUS_MAX_REFERRALS_EXCEEDED                                      ((NTSTATUS)0xC00002F4) /**< The number of maximum ticket referrals has been exceeded. */
#define STATUS_MUST_BE_KDC                                                 ((NTSTATUS)0xC00002F5) /**< The local machine must be a Kerberos KDC (domain controller) and it is not. */
#define STATUS_STRONG_CRYPTO_NOT_SUPPORTED                                 ((NTSTATUS)0xC00002F6) /**< The other end of the security negotiation requires strong crypto but it is not supported on the local machine. */
#define STATUS_TOO_MANY_PRINCIPALS                                         ((NTSTATUS)0xC00002F7) /**< The KDC reply contained more than one principal name. */
#define STATUS_NO_PA_DATA                                                  ((NTSTATUS)0xC00002F8) /**< Expected to find PA data for a hint of what etype to use, but it was not found. */
#define STATUS_PKINIT_NAME_MISMATCH                                        ((NTSTATUS)0xC00002F9) /**< The client certificate does not contain a valid UPN, or does not match the client name in the logon request. Contact your administrator. */
#define STATUS_SMARTCARD_LOGON_REQUIRED                                    ((NTSTATUS)0xC00002FA) /**< Smart card logon is required and was not used. */
#define STATUS_KDC_INVALID_REQUEST                                         ((NTSTATUS)0xC00002FB) /**< An invalid request was sent to the KDC. */
#define STATUS_KDC_UNABLE_TO_REFER                                         ((NTSTATUS)0xC00002FC) /**< The KDC was unable to generate a referral for the service requested. */
#define STATUS_KDC_UNKNOWN_ETYPE                                           ((NTSTATUS)0xC00002FD) /**< The encryption type requested is not supported by the KDC. */
#define STATUS_SHUTDOWN_IN_PROGRESS                                        ((NTSTATUS)0xC00002FE) /**< A system shutdown is in progress. */
#define STATUS_SERVER_SHUTDOWN_IN_PROGRESS                                 ((NTSTATUS)0xC00002FF) /**< The server machine is shutting down. */
#define STATUS_NOT_SUPPORTED_ON_SBS                                        ((NTSTATUS)0xC0000300) /**< This operation is not supported on a computer running Windows Server 2003 operating system for Small Business Server. */
#define STATUS_WMI_GUID_DISCONNECTED                                       ((NTSTATUS)0xC0000301) /**< The WMI GUID is no longer available. */
#define STATUS_WMI_ALREADY_DISABLED                                        ((NTSTATUS)0xC0000302) /**< Collection or events for the WMI GUID is already disabled. */
#define STATUS_WMI_ALREADY_ENABLED                                         ((NTSTATUS)0xC0000303) /**< Collection or events for the WMI GUID is already enabled. */
#define STATUS_MFT_TOO_FRAGMENTED                                          ((NTSTATUS)0xC0000304) /**< The master file table on the volume is too fragmented to complete this operation. */
#define STATUS_COPY_PROTECTION_FAILURE                                     ((NTSTATUS)0xC0000305) /**< Copy protection failure. */
#define STATUS_CSS_AUTHENTICATION_FAILURE                                  ((NTSTATUS)0xC0000306) /**< Copy protection error—DVD CSS Authentication failed. */
#define STATUS_CSS_KEY_NOT_PRESENT                                         ((NTSTATUS)0xC0000307) /**< Copy protection error—The specified sector does not contain a valid key. */
#define STATUS_CSS_KEY_NOT_ESTABLISHED                                     ((NTSTATUS)0xC0000308) /**< Copy protection error—DVD session key not established. */
#define STATUS_CSS_SCRAMBLED_SECTOR                                        ((NTSTATUS)0xC0000309) /**< Copy protection error—The read failed because the sector is encrypted. */
#define STATUS_CSS_REGION_MISMATCH                                         ((NTSTATUS)0xC000030A) /**< Copy protection error—The region of the specified DVD does not correspond to the region setting of the drive. */
#define STATUS_CSS_RESETS_EXHAUSTED                                        ((NTSTATUS)0xC000030B) /**< Copy protection error—The region setting of the drive might be permanent. */
#define STATUS_PKINIT_FAILURE                                              ((NTSTATUS)0xC0000320) /**< The Kerberos protocol encountered an error while validating the KDC certificate during smart card logon. There is more information in the system event log. */
#define STATUS_SMARTCARD_SUBSYSTEM_FAILURE                                 ((NTSTATUS)0xC0000321) /**< The Kerberos protocol encountered an error while attempting to use the smart card subsystem. */
#define STATUS_NO_KERB_KEY                                                 ((NTSTATUS)0xC0000322) /**< The target server does not have acceptable Kerberos credentials. */
#define STATUS_HOST_DOWN                                                   ((NTSTATUS)0xC0000350) /**< The transport determined that the remote system is down. */
#define STATUS_UNSUPPORTED_PREAUTH                                         ((NTSTATUS)0xC0000351) /**< An unsupported pre-authentication mechanism was presented to the Kerberos package. */
#define STATUS_EFS_ALG_BLOB_TOO_BIG                                        ((NTSTATUS)0xC0000352) /**< The encryption algorithm that is used on the source file needs a bigger key buffer than the one that is used on the destination file. */
#define STATUS_PORT_NOT_SET                                                ((NTSTATUS)0xC0000353) /**< An attempt to remove a processes DebugPort was made, but a port was not already associated with the process. */
#define STATUS_DEBUGGER_INACTIVE                                           ((NTSTATUS)0xC0000354) /**< An attempt to do an operation on a debug port failed because the port is in the process of being deleted. */
#define STATUS_DS_VERSION_CHECK_FAILURE                                    ((NTSTATUS)0xC0000355) /**< This version of Windows is not compatible with the behavior version of the directory forest, domain, or domain controller. */
#define STATUS_AUDITING_DISABLED                                           ((NTSTATUS)0xC0000356) /**< The specified event is currently not being audited. */
#define STATUS_PRENT4_MACHINE_ACCOUNT                                      ((NTSTATUS)0xC0000357) /**< The machine account was created prior to Windows NT 4.0 operating system. The account needs to be recreated. */
#define STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER                            ((NTSTATUS)0xC0000358) /**< An account group cannot have a universal group as a member. */
#define STATUS_INVALID_IMAGE_WIN_32                                        ((NTSTATUS)0xC0000359) /**< The specified image file did not have the correct format; it appears to be a 32-bit Windows image. */
#define STATUS_INVALID_IMAGE_WIN_64                                        ((NTSTATUS)0xC000035A) /**< The specified image file did not have the correct format; it appears to be a 64-bit Windows image. */
#define STATUS_BAD_BINDINGS                                                ((NTSTATUS)0xC000035B) /**< The client's supplied SSPI channel bindings were incorrect. */
#define STATUS_NETWORK_SESSION_EXPIRED                                     ((NTSTATUS)0xC000035C) /**< The client session has expired; so the client must re-authenticate to continue accessing the remote resources. */
#define STATUS_APPHELP_BLOCK                                               ((NTSTATUS)0xC000035D) /**< The AppHelp dialog box canceled; thus preventing the application from starting. */
#define STATUS_ALL_SIDS_FILTERED                                           ((NTSTATUS)0xC000035E) /**< The SID filtering operation removed all SIDs. */
#define STATUS_NOT_SAFE_MODE_DRIVER                                        ((NTSTATUS)0xC000035F) /**< The driver was not loaded because the system is starting in safe mode. */
#define STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT                           ((NTSTATUS)0xC0000361) /**< Access to %1 has been restricted by your Administrator by the default software restriction policy level. */
#define STATUS_ACCESS_DISABLED_BY_POLICY_PATH                              ((NTSTATUS)0xC0000362) /**< Access to %1 has been restricted by your Administrator by location with policy rule %2 placed on path %3. */
#define STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER                         ((NTSTATUS)0xC0000363) /**< Access to %1 has been restricted by your Administrator by software publisher policy. */
#define STATUS_ACCESS_DISABLED_BY_POLICY_OTHER                             ((NTSTATUS)0xC0000364) /**< Access to %1 has been restricted by your Administrator by policy rule %2. */
#define STATUS_FAILED_DRIVER_ENTRY                                         ((NTSTATUS)0xC0000365) /**< The driver was not loaded because it failed its initialization call. */
#define STATUS_DEVICE_ENUMERATION_ERROR                                    ((NTSTATUS)0xC0000366) /**< The device encountered an error while applying power or reading the device configuration. This might be caused by a failure of your hardware or by a poor connection. */
#define STATUS_MOUNT_POINT_NOT_RESOLVED                                    ((NTSTATUS)0xC0000368) /**< The create operation failed because the name contained at least one mount point that resolves to a volume to which the specified device object is not attached. */
#define STATUS_INVALID_DEVICE_OBJECT_PARAMETER                             ((NTSTATUS)0xC0000369) /**< The device object parameter is either not a valid device object or is not attached to the volume that is specified by the file name. */
#define STATUS_MCA_OCCURED                                                 ((NTSTATUS)0xC000036A) /**< A machine check error has occurred. Check the system event log for additional information. */
#define STATUS_DRIVER_BLOCKED_CRITICAL                                     ((NTSTATUS)0xC000036B) /**< Driver %2 has been blocked from loading. */
#define STATUS_DRIVER_BLOCKED                                              ((NTSTATUS)0xC000036C) /**< Driver %2 has been blocked from loading. */
#define STATUS_DRIVER_DATABASE_ERROR                                       ((NTSTATUS)0xC000036D) /**< There was error [%2] processing the driver database. */
#define STATUS_SYSTEM_HIVE_TOO_LARGE                                       ((NTSTATUS)0xC000036E) /**< System hive size has exceeded its limit. */
#define STATUS_INVALID_IMPORT_OF_NON_DLL                                   ((NTSTATUS)0xC000036F) /**< A dynamic link library (DLL) referenced a module that was neither a DLL nor the process's executable image. */
#define STATUS_NO_SECRETS                                                  ((NTSTATUS)0xC0000371) /**< The local account store does not contain secret material for the specified account. */
#define STATUS_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY                       ((NTSTATUS)0xC0000372) /**< Access to %1 has been restricted by your Administrator by policy rule %2. */
#define STATUS_FAILED_STACK_SWITCH                                         ((NTSTATUS)0xC0000373) /**< The system was not able to allocate enough memory to perform a stack switch. */
#define STATUS_HEAP_CORRUPTION                                             ((NTSTATUS)0xC0000374) /**< A heap has been corrupted. */
#define STATUS_SMARTCARD_WRONG_PIN                                         ((NTSTATUS)0xC0000380) /**< An incorrect PIN was presented to the smart card. */
#define STATUS_SMARTCARD_CARD_BLOCKED                                      ((NTSTATUS)0xC0000381) /**< The smart card is blocked. */
#define STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED                            ((NTSTATUS)0xC0000382) /**< No PIN was presented to the smart card. */
#define STATUS_SMARTCARD_NO_CARD                                           ((NTSTATUS)0xC0000383) /**< No smart card is available. */
#define STATUS_SMARTCARD_NO_KEY_CONTAINER                                  ((NTSTATUS)0xC0000384) /**< The requested key container does not exist on the smart card. */
#define STATUS_SMARTCARD_NO_CERTIFICATE                                    ((NTSTATUS)0xC0000385) /**< The requested certificate does not exist on the smart card. */
#define STATUS_SMARTCARD_NO_KEYSET                                         ((NTSTATUS)0xC0000386) /**< The requested keyset does not exist. */
#define STATUS_SMARTCARD_IO_ERROR                                          ((NTSTATUS)0xC0000387) /**< A communication error with the smart card has been detected. */
#define STATUS_DOWNGRADE_DETECTED                                          ((NTSTATUS)0xC0000388) /**< The system detected a possible attempt to compromise security. Ensure that you can contact the server that authenticated you. */
#define STATUS_SMARTCARD_CERT_REVOKED                                      ((NTSTATUS)0xC0000389) /**< The smart card certificate used for authentication has been revoked. Contact your system administrator. There might be additional information in the event log. */
#define STATUS_ISSUING_CA_UNTRUSTED                                        ((NTSTATUS)0xC000038A) /**< An untrusted certificate authority was detected while processing the smart card certificate that is used for authentication. Contact your system administrator. */
#define STATUS_REVOCATION_OFFLINE_C                                        ((NTSTATUS)0xC000038B) /**< The revocation status of the smart card certificate that is used for authentication could not be determined. Contact your system administrator. */
#define STATUS_PKINIT_CLIENT_FAILURE                                       ((NTSTATUS)0xC000038C) /**< The smart card certificate used for authentication was not trusted. Contact your system administrator. */
#define STATUS_SMARTCARD_CERT_EXPIRED                                      ((NTSTATUS)0xC000038D) /**< The smart card certificate used for authentication has expired. Contact your system administrator. */
#define STATUS_DRIVER_FAILED_PRIOR_UNLOAD                                  ((NTSTATUS)0xC000038E) /**< The driver could not be loaded because a previous version of the driver is still in memory. */
#define STATUS_SMARTCARD_SILENT_CONTEXT                                    ((NTSTATUS)0xC000038F) /**< The smart card provider could not perform the action because the context was acquired as silent. */
#define STATUS_PER_USER_TRUST_QUOTA_EXCEEDED                               ((NTSTATUS)0xC0000401) /**< The delegated trust creation quota of the current user has been exceeded. */
#define STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED                               ((NTSTATUS)0xC0000402) /**< The total delegated trust creation quota has been exceeded. */
#define STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED                            ((NTSTATUS)0xC0000403) /**< The delegated trust deletion quota of the current user has been exceeded. */
#define STATUS_DS_NAME_NOT_UNIQUE                                          ((NTSTATUS)0xC0000404) /**< The requested name already exists as a unique identifier. */
#define STATUS_DS_DUPLICATE_ID_FOUND                                       ((NTSTATUS)0xC0000405) /**< The requested object has a non-unique identifier and cannot be retrieved. */
#define STATUS_DS_GROUP_CONVERSION_ERROR                                   ((NTSTATUS)0xC0000406) /**< The group cannot be converted due to attribute restrictions on the requested group type. */
#define STATUS_VOLSNAP_PREPARE_HIBERNATE                                   ((NTSTATUS)0xC0000407) /**< {Volume Shadow Copy Service} Wait while the Volume Shadow Copy Service prepares volume %hs for hibernation. */
#define STATUS_USER2USER_REQUIRED                                          ((NTSTATUS)0xC0000408) /**< Kerberos sub-protocol User2User is required. */
#define STATUS_STACK_BUFFER_OVERRUN                                        ((NTSTATUS)0xC0000409) /**< The system detected an overrun of a stack-based buffer in this application. This overrun could potentially allow a malicious user to gain control of this application. */
#define STATUS_NO_S4U_PROT_SUPPORT                                         ((NTSTATUS)0xC000040A) /**< The Kerberos subsystem encountered an error. A service for user protocol request was made against a domain controller which does not support service for user. */
#define STATUS_CROSSREALM_DELEGATION_FAILURE                               ((NTSTATUS)0xC000040B) /**< An attempt was made by this server to make a Kerberos constrained delegation request for a target that is outside the server realm. This action is not supported and the resulting error indicates a misconfiguration on the allowed-to-delegate-to list for this server. Contact your administrator. */
#define STATUS_REVOCATION_OFFLINE_KDC                                      ((NTSTATUS)0xC000040C) /**< The revocation status of the domain controller certificate used for smart card authentication could not be determined. There is additional information in the system event log. Contact your system administrator. */
#define STATUS_ISSUING_CA_UNTRUSTED_KDC                                    ((NTSTATUS)0xC000040D) /**< An untrusted certificate authority was detected while processing the domain controller certificate used for authentication. There is additional information in the system event log. Contact your system administrator. */
#define STATUS_KDC_CERT_EXPIRED                                            ((NTSTATUS)0xC000040E) /**< The domain controller certificate used for smart card logon has expired. Contact your system administrator with the contents of your system event log. */
#define STATUS_KDC_CERT_REVOKED                                            ((NTSTATUS)0xC000040F) /**< The domain controller certificate used for smart card logon has been revoked. Contact your system administrator with the contents of your system event log. */
#define STATUS_PARAMETER_QUOTA_EXCEEDED                                    ((NTSTATUS)0xC0000410) /**< Data present in one of the parameters is more than the function can operate on. */
#define STATUS_HIBERNATION_FAILURE                                         ((NTSTATUS)0xC0000411) /**< The system has failed to hibernate (The error code is %hs). Hibernation will be disabled until the system is restarted. */
#define STATUS_DELAY_LOAD_FAILED                                           ((NTSTATUS)0xC0000412) /**< An attempt to delay-load a .dll or get a function address in a delay-loaded .dll failed. */
#define STATUS_AUTHENTICATION_FIREWALL_FAILED                              ((NTSTATUS)0xC0000413) /**< Logon Failure: The machine you are logging onto is protected by an authentication firewall. The specified account is not allowed to authenticate to the machine. */
#define STATUS_VDM_DISALLOWED                                              ((NTSTATUS)0xC0000414) /**< %hs is a 16-bit application. You do not have permissions to execute 16-bit applications. Check your permissions with your system administrator. */
#define STATUS_HUNG_DISPLAY_DRIVER_THREAD                                  ((NTSTATUS)0xC0000415) /**< {Display Driver Stopped Responding} The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality. The next time you reboot the machine a dialog will be displayed giving you a chance to report this failure to Microsoft. */
#define STATUS_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE     ((NTSTATUS)0xC0000416) /**< The Desktop heap encountered an error while allocating session memory. There is more information in the system event log. */
#define STATUS_INVALID_CRUNTIME_PARAMETER                                  ((NTSTATUS)0xC0000417) /**< An invalid parameter was passed to a C runtime function. */
#define STATUS_NTLM_BLOCKED                                                ((NTSTATUS)0xC0000418) /**< The authentication failed because NTLM was blocked. */
#define STATUS_DS_SRC_SID_EXISTS_IN_FOREST                                 ((NTSTATUS)0xC0000419) /**< The source object's SID already exists in destination forest. */
#define STATUS_DS_DOMAIN_NAME_EXISTS_IN_FOREST                             ((NTSTATUS)0xC000041A) /**< The domain name of the trusted domain already exists in the forest. */
#define STATUS_DS_FLAT_NAME_EXISTS_IN_FOREST                               ((NTSTATUS)0xC000041B) /**< The flat name of the trusted domain already exists in the forest. */
#define STATUS_INVALID_USER_PRINCIPAL_NAME                                 ((NTSTATUS)0xC000041C) /**< The User Principal Name (UPN) is invalid. */
#define STATUS_ASSERTION_FAILURE                                           ((NTSTATUS)0xC0000420) /**< There has been an assertion failure. */
#define STATUS_VERIFIER_STOP                                               ((NTSTATUS)0xC0000421) /**< Application verifier has found an error in the current process. */
#define STATUS_CALLBACK_POP_STACK                                          ((NTSTATUS)0xC0000423) /**< A user mode unwind is in progress. */
#define STATUS_INCOMPATIBLE_DRIVER_BLOCKED                                 ((NTSTATUS)0xC0000424) /**< %2 has been blocked from loading due to incompatibility with this system. Contact your software vendor for a compatible version of the driver. */
#define STATUS_HIVE_UNLOADED                                               ((NTSTATUS)0xC0000425) /**< Illegal operation attempted on a registry key which has already been unloaded. */
#define STATUS_COMPRESSION_DISABLED                                        ((NTSTATUS)0xC0000426) /**< Compression is disabled for this volume. */
#define STATUS_FILE_SYSTEM_LIMITATION                                      ((NTSTATUS)0xC0000427) /**< The requested operation could not be completed due to a file system limitation. */
#define STATUS_INVALID_IMAGE_HASH                                          ((NTSTATUS)0xC0000428) /**< The hash for image %hs cannot be found in the system catalogs. The image is likely corrupt or the victim of tampering. */
#define STATUS_NOT_CAPABLE                                                 ((NTSTATUS)0xC0000429) /**< The implementation is not capable of performing the request. */
#define STATUS_REQUEST_OUT_OF_SEQUENCE                                     ((NTSTATUS)0xC000042A) /**< The requested operation is out of order with respect to other operations. */
#define STATUS_IMPLEMENTATION_LIMIT                                        ((NTSTATUS)0xC000042B) /**< An operation attempted to exceed an implementation-defined limit. */
#define STATUS_ELEVATION_REQUIRED                                          ((NTSTATUS)0xC000042C) /**< The requested operation requires elevation. */
#define STATUS_NO_SECURITY_CONTEXT                                         ((NTSTATUS)0xC000042D) /**< The required security context does not exist. */
#define STATUS_PKU2U_CERT_FAILURE                                          ((NTSTATUS)0xC000042E) /**< The PKU2U protocol encountered an error while attempting to utilize the associated certificates. */
#define STATUS_BEYOND_VDL                                                  ((NTSTATUS)0xC0000432) /**< The operation was attempted beyond the valid data length of the file. */
#define STATUS_ENCOUNTERED_WRITE_IN_PROGRESS                               ((NTSTATUS)0xC0000433) /**< The attempted write operation encountered a write already in progress for some portion of the range. */
#define STATUS_PTE_CHANGED                                                 ((NTSTATUS)0xC0000434) /**< The page fault mappings changed in the middle of processing a fault so the operation must be retried. */
#define STATUS_PURGE_FAILED                                                ((NTSTATUS)0xC0000435) /**< The attempt to purge this file from memory failed to purge some or all the data from memory. */
#define STATUS_CRED_REQUIRES_CONFIRMATION                                  ((NTSTATUS)0xC0000440) /**< The requested credential requires confirmation. */
#define STATUS_CS_ENCRYPTION_INVALID_SERVER_RESPONSE                       ((NTSTATUS)0xC0000441) /**< The remote server sent an invalid response for a file being opened with Client Side Encryption. */
#define STATUS_CS_ENCRYPTION_UNSUPPORTED_SERVER                            ((NTSTATUS)0xC0000442) /**< Client Side Encryption is not supported by the remote server even though it claims to support it. */
#define STATUS_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE                       ((NTSTATUS)0xC0000443) /**< File is encrypted and should be opened in Client Side Encryption mode. */
#define STATUS_CS_ENCRYPTION_NEW_ENCRYPTED_FILE                            ((NTSTATUS)0xC0000444) /**< A new encrypted file is being created and a $EFS needs to be provided. */
#define STATUS_CS_ENCRYPTION_FILE_NOT_CSE                                  ((NTSTATUS)0xC0000445) /**< The SMB client requested a CSE FSCTL on a non-CSE file. */
#define STATUS_INVALID_LABEL                                               ((NTSTATUS)0xC0000446) /**< Indicates a particular Security ID cannot be assigned as the label of an object. */
#define STATUS_DRIVER_PROCESS_TERMINATED                                   ((NTSTATUS)0xC0000450) /**< The process hosting the driver for this device has terminated. */
#define STATUS_AMBIGUOUS_SYSTEM_DEVICE                                     ((NTSTATUS)0xC0000451) /**< The requested system device cannot be identified due to multiple indistinguishable devices potentially matching the identification criteria. */
#define STATUS_SYSTEM_DEVICE_NOT_FOUND                                     ((NTSTATUS)0xC0000452) /**< The requested system device cannot be found. */
#define STATUS_RESTART_BOOT_APPLICATION                                    ((NTSTATUS)0xC0000453) /**< This boot application must be restarted. */
#define STATUS_INSUFFICIENT_NVRAM_RESOURCES                                ((NTSTATUS)0xC0000454) /**< Insufficient NVRAM resources exist to complete the API.  A reboot might be required. */
#define STATUS_NO_RANGES_PROCESSED                                         ((NTSTATUS)0xC0000460) /**< No ranges for the specified operation were able to be processed. */
#define STATUS_DEVICE_FEATURE_NOT_SUPPORTED                                ((NTSTATUS)0xC0000463) /**< The storage device does not support Offload Write. */
#define STATUS_DEVICE_UNREACHABLE                                          ((NTSTATUS)0xC0000464) /**< Data cannot be moved because the source device cannot communicate with the destination device. */
#define STATUS_INVALID_TOKEN                                               ((NTSTATUS)0xC0000465) /**< The token representing the data is invalid or expired. */
#define STATUS_SERVER_UNAVAILABLE                                          ((NTSTATUS)0xC0000466) /**< The file server is temporarily unavailable. */
#define STATUS_INVALID_TASK_NAME                                           ((NTSTATUS)0xC0000500) /**< The specified task name is invalid. */
#define STATUS_INVALID_TASK_INDEX                                          ((NTSTATUS)0xC0000501) /**< The specified task index is invalid. */
#define STATUS_THREAD_ALREADY_IN_TASK                                      ((NTSTATUS)0xC0000502) /**< The specified thread is already joining a task. */
#define STATUS_CALLBACK_BYPASS                                             ((NTSTATUS)0xC0000503) /**< A callback has requested to bypass native code. */
#define STATUS_FAIL_FAST_EXCEPTION                                         ((NTSTATUS)0xC0000602) /**< A fail fast exception occurred. Exception handlers will not be invoked and the process will be terminated immediately. */
#define STATUS_IMAGE_CERT_REVOKED                                          ((NTSTATUS)0xC0000603) /**< Windows cannot verify the digital signature for this file. The signing certificate for this file has been revoked. */
#define STATUS_PORT_CLOSED                                                 ((NTSTATUS)0xC0000700) /**< The ALPC port is closed. */
#define STATUS_MESSAGE_LOST                                                ((NTSTATUS)0xC0000701) /**< The ALPC message requested is no longer available. */
#define STATUS_INVALID_MESSAGE                                             ((NTSTATUS)0xC0000702) /**< The ALPC message supplied is invalid. */
#define STATUS_REQUEST_CANCELED                                            ((NTSTATUS)0xC0000703) /**< The ALPC message has been canceled. */
#define STATUS_RECURSIVE_DISPATCH                                          ((NTSTATUS)0xC0000704) /**< Invalid recursive dispatch attempt. */
#define STATUS_LPC_RECEIVE_BUFFER_EXPECTED                                 ((NTSTATUS)0xC0000705) /**< No receive buffer has been supplied in a synchronous request. */
#define STATUS_LPC_INVALID_CONNECTION_USAGE                                ((NTSTATUS)0xC0000706) /**< The connection port is used in an invalid context. */
#define STATUS_LPC_REQUESTS_NOT_ALLOWED                                    ((NTSTATUS)0xC0000707) /**< The ALPC port does not accept new request messages. */
#define STATUS_RESOURCE_IN_USE                                             ((NTSTATUS)0xC0000708) /**< The resource requested is already in use. */
#define STATUS_HARDWARE_MEMORY_ERROR                                       ((NTSTATUS)0xC0000709) /**< The hardware has reported an uncorrectable memory error. */
#define STATUS_THREADPOOL_HANDLE_EXCEPTION                                 ((NTSTATUS)0xC000070A) /**< Status 0x%08x was returned, waiting on handle 0x%x for wait 0x%p, in waiter 0x%p. */
#define STATUS_THREADPOOL_SET_EVENT_ON_COMPLETION_FAILED                   ((NTSTATUS)0xC000070B) /**< After a callback to 0x%p(0x%p), a completion call to Set event(0x%p) failed with status 0x%08x. */
#define STATUS_THREADPOOL_RELEASE_SEMAPHORE_ON_COMPLETION_FAILED           ((NTSTATUS)0xC000070C) /**< After a callback to 0x%p(0x%p), a completion call to ReleaseSemaphore(0x%p, %d) failed with status 0x%08x. */
#define STATUS_THREADPOOL_RELEASE_MUTEX_ON_COMPLETION_FAILED               ((NTSTATUS)0xC000070D) /**< After a callback to 0x%p(0x%p), a completion call to ReleaseMutex(%p) failed with status 0x%08x. */
#define STATUS_THREADPOOL_FREE_LIBRARY_ON_COMPLETION_FAILED                ((NTSTATUS)0xC000070E) /**< After a callback to 0x%p(0x%p), a completion call to FreeLibrary(%p) failed with status 0x%08x. */
#define STATUS_THREADPOOL_RELEASED_DURING_OPERATION                        ((NTSTATUS)0xC000070F) /**< The thread pool 0x%p was released while a thread was posting a callback to 0x%p(0x%p) to it. */
#define STATUS_CALLBACK_RETURNED_WHILE_IMPERSONATING                       ((NTSTATUS)0xC0000710) /**< A thread pool worker thread is impersonating a client, after a callback to 0x%p(0x%p). This is unexpected, indicating that the callback is missing a call to revert the impersonation. */
#define STATUS_APC_RETURNED_WHILE_IMPERSONATING                            ((NTSTATUS)0xC0000711) /**< A thread pool worker thread is impersonating a client, after executing an APC. This is unexpected, indicating that the APC is missing a call to revert the impersonation. */
#define STATUS_PROCESS_IS_PROTECTED                                        ((NTSTATUS)0xC0000712) /**< Either the target process, or the target thread's containing process, is a protected process. */
#define STATUS_MCA_EXCEPTION                                               ((NTSTATUS)0xC0000713) /**< A thread is getting dispatched with MCA EXCEPTION because of MCA. */
#define STATUS_CERTIFICATE_MAPPING_NOT_UNIQUE                              ((NTSTATUS)0xC0000714) /**< The client certificate account mapping is not unique. */
#define STATUS_SYMLINK_CLASS_DISABLED                                      ((NTSTATUS)0xC0000715) /**< The symbolic link cannot be followed because its type is disabled. */
#define STATUS_INVALID_IDN_NORMALIZATION                                   ((NTSTATUS)0xC0000716) /**< Indicates that the specified string is not valid for IDN normalization. */
#define STATUS_NO_UNICODE_TRANSLATION                                      ((NTSTATUS)0xC0000717) /**< No mapping for the Unicode character exists in the target multi-byte code page. */
#define STATUS_ALREADY_REGISTERED                                          ((NTSTATUS)0xC0000718) /**< The provided callback is already registered. */
#define STATUS_CONTEXT_MISMATCH                                            ((NTSTATUS)0xC0000719) /**< The provided context did not match the target. */
#define STATUS_PORT_ALREADY_HAS_COMPLETION_LIST                            ((NTSTATUS)0xC000071A) /**< The specified port already has a completion list. */
#define STATUS_CALLBACK_RETURNED_THREAD_PRIORITY                           ((NTSTATUS)0xC000071B) /**< A threadpool worker thread entered a callback at thread base priority 0x%x and exited at priority 0x%x. This is unexpected, indicating that the callback missed restoring the priority. */
#define STATUS_INVALID_THREAD                                              ((NTSTATUS)0xC000071C) /**< An invalid thread, handle %p, is specified for this operation. Possibly, a threadpool worker thread was specified. */
#define STATUS_CALLBACK_RETURNED_TRANSACTION                               ((NTSTATUS)0xC000071D) /**< A threadpool worker thread entered a callback, which left transaction state. This is unexpected, indicating that the callback missed clearing the transaction. */
#define STATUS_CALLBACK_RETURNED_LDR_LOCK                                  ((NTSTATUS)0xC000071E) /**< A threadpool worker thread entered a callback, which left the loader lock held. This is unexpected, indicating that the callback missed releasing the lock. */
#define STATUS_CALLBACK_RETURNED_LANG                                      ((NTSTATUS)0xC000071F) /**< A threadpool worker thread entered a callback, which left with preferred languages set. This is unexpected, indicating that the callback missed clearing them. */
#define STATUS_CALLBACK_RETURNED_PRI_BACK                                  ((NTSTATUS)0xC0000720) /**< A threadpool worker thread entered a callback, which left with background priorities set. This is unexpected, indicating that the callback missed restoring the original priorities. */
#define STATUS_DISK_REPAIR_DISABLED                                        ((NTSTATUS)0xC0000800) /**< The attempted operation required self healing to be enabled. */
#define STATUS_DS_DOMAIN_RENAME_IN_PROGRESS                                ((NTSTATUS)0xC0000801) /**< The directory service cannot perform the requested operation because a domain rename operation is in progress. */
#define STATUS_DISK_QUOTA_EXCEEDED                                         ((NTSTATUS)0xC0000802) /**< An operation failed because the storage quota was exceeded. */
#define STATUS_CONTENT_BLOCKED                                             ((NTSTATUS)0xC0000804) /**< An operation failed because the content was blocked. */
#define STATUS_BAD_CLUSTERS                                                ((NTSTATUS)0xC0000805) /**< The operation could not be completed due to bad clusters on disk. */
#define STATUS_VOLUME_DIRTY                                                ((NTSTATUS)0xC0000806) /**< The operation could not be completed because the volume is dirty. Please run the Chkdsk utility and try again. */
#define STATUS_FILE_CHECKED_OUT                                            ((NTSTATUS)0xC0000901) /**< This file is checked out or locked for editing by another user. */
#define STATUS_CHECKOUT_REQUIRED                                           ((NTSTATUS)0xC0000902) /**< The file must be checked out before saving changes. */
#define STATUS_BAD_FILE_TYPE                                               ((NTSTATUS)0xC0000903) /**< The file type being saved or retrieved has been blocked. */
#define STATUS_FILE_TOO_LARGE                                              ((NTSTATUS)0xC0000904) /**< The file size exceeds the limit allowed and cannot be saved. */
#define STATUS_FORMS_AUTH_REQUIRED                                         ((NTSTATUS)0xC0000905) /**< Access Denied. Before opening files in this location, you must first browse to the e.g. site and select the option to log on automatically. */
#define STATUS_VIRUS_INFECTED                                              ((NTSTATUS)0xC0000906) /**< The operation did not complete successfully because the file contains a virus. */
#define STATUS_VIRUS_DELETED                                               ((NTSTATUS)0xC0000907) /**< This file contains a virus and cannot be opened. Due to the nature of this virus, the file has been removed from this location. */
#define STATUS_BAD_MCFG_TABLE                                              ((NTSTATUS)0xC0000908) /**< The resources required for this device conflict with the MCFG table. */
#define STATUS_BAD_DATA                                                    ((NTSTATUS)0xC000090B) /**< Bad data. */
#define STATUS_CANNOT_BREAK_OPLOCK                                         ((NTSTATUS)0xC0000909) /**< The operation did not complete successfully because it would cause an oplock to be broken. The caller has requested that existing oplocks not be broken. */
#define STATUS_WOW_ASSERTION                                               ((NTSTATUS)0xC0009898) /**< WOW Assertion Error. */
#define STATUS_INVALID_SIGNATURE                                           ((NTSTATUS)0xC000A000) /**< The cryptographic signature is invalid. */
#define STATUS_HMAC_NOT_SUPPORTED                                          ((NTSTATUS)0xC000A001) /**< The cryptographic provider does not support HMAC. */
#define STATUS_AUTH_TAG_MISMATCH                                           ((NTSTATUS)0xC000A002) /**< The computed authentication tag did not match the input authentication tag. */
#define STATUS_IPSEC_QUEUE_OVERFLOW                                        ((NTSTATUS)0xC000A010) /**< The IPsec queue overflowed. */
#define STATUS_ND_QUEUE_OVERFLOW                                           ((NTSTATUS)0xC000A011) /**< The neighbor discovery queue overflowed. */
#define STATUS_HOPLIMIT_EXCEEDED                                           ((NTSTATUS)0xC000A012) /**< An Internet Control Message Protocol (ICMP) hop limit exceeded error was received. */
#define STATUS_PROTOCOL_NOT_SUPPORTED                                      ((NTSTATUS)0xC000A013) /**< The protocol is not installed on the local machine. */
#define STATUS_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED                  ((NTSTATUS)0xC000A080) /**< {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error might be caused by network connectivity issues. Try to save this file elsewhere. */
#define STATUS_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR                  ((NTSTATUS)0xC000A081) /**< {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error was returned by the server on which the file exists. Try to save this file elsewhere. */
#define STATUS_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR                      ((NTSTATUS)0xC000A082) /**< {Delayed Write Failed} Windows was unable to save all the data for the file %hs; the data has been lost. This error might be caused if the device has been removed or the media is write-protected. */
#define STATUS_XML_PARSE_ERROR                                             ((NTSTATUS)0xC000A083) /**< Windows was unable to parse the requested XML data. */
#define STATUS_XMLDSIG_ERROR                                               ((NTSTATUS)0xC000A084) /**< An error was encountered while processing an XML digital signature. */
#define STATUS_WRONG_COMPARTMENT                                           ((NTSTATUS)0xC000A085) /**< This indicates that the caller made the connection request in the wrong routing compartment. */
#define STATUS_AUTHIP_FAILURE                                              ((NTSTATUS)0xC000A086) /**< This indicates that there was an AuthIP failure when attempting to connect to the remote host. */
#define STATUS_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS                       ((NTSTATUS)0xC000A087) /**< OID mapped groups cannot have members. */
#define STATUS_DS_OID_NOT_FOUND                                            ((NTSTATUS)0xC000A088) /**< The specified OID cannot be found. */
#define STATUS_HASH_NOT_SUPPORTED                                          ((NTSTATUS)0xC000A100) /**< Hash generation for the specified version and hash type is not enabled on server. */
#define STATUS_HASH_NOT_PRESENT                                            ((NTSTATUS)0xC000A101) /**< The hash requests is not present or not up to date with the current file contents. */
#define STATUS_OFFLOAD_READ_FLT_NOT_SUPPORTED                              ((NTSTATUS)0xC000A2A1) /**< A file system filter on the server has not opted in for Offload Read support. */
#define STATUS_OFFLOAD_WRITE_FLT_NOT_SUPPORTED                             ((NTSTATUS)0xC000A2A2) /**< A file system filter on the server has not opted in for Offload Write support. */
#define STATUS_OFFLOAD_READ_FILE_NOT_SUPPORTED                             ((NTSTATUS)0xC000A2A3) /**< Offload read operations cannot be performed on: Compressed files Sparse files Encrypted files File system metadata files */
#define STATUS_OFFLOAD_WRITE_FILE_NOT_SUPPORTED                            ((NTSTATUS)0xC000A2A4) /**< Offload write operations cannot be performed on: Compressed files Sparse files Encrypted files File system metadata files */
#define DBG_NO_STATE_CHANGE                                                ((NTSTATUS)0xC0010001) /**< The debugger did not perform a state change. */
#define DBG_APP_NOT_IDLE                                                   ((NTSTATUS)0xC0010002) /**< The debugger found that the application is not idle. */
#define RPC_NT_INVALID_STRING_BINDING                                      ((NTSTATUS)0xC0020001) /**< The string binding is invalid. */
#define RPC_NT_WRONG_KIND_OF_BINDING                                       ((NTSTATUS)0xC0020002) /**< The binding handle is not the correct type. */
#define RPC_NT_INVALID_BINDING                                             ((NTSTATUS)0xC0020003) /**< The binding handle is invalid. */
#define RPC_NT_PROTSEQ_NOT_SUPPORTED                                       ((NTSTATUS)0xC0020004) /**< The RPC protocol sequence is not supported. */
#define RPC_NT_INVALID_RPC_PROTSEQ                                         ((NTSTATUS)0xC0020005) /**< The RPC protocol sequence is invalid. */
#define RPC_NT_INVALID_STRING_UUID                                         ((NTSTATUS)0xC0020006) /**< The string UUID is invalid. */
#define RPC_NT_INVALID_ENDPOINT_FORMAT                                     ((NTSTATUS)0xC0020007) /**< The endpoint format is invalid. */
#define RPC_NT_INVALID_NET_ADDR                                            ((NTSTATUS)0xC0020008) /**< The network address is invalid. */
#define RPC_NT_NO_ENDPOINT_FOUND                                           ((NTSTATUS)0xC0020009) /**< No endpoint was found. */
#define RPC_NT_INVALID_TIMEOUT                                             ((NTSTATUS)0xC002000A) /**< The time-out value is invalid. */
#define RPC_NT_OBJECT_NOT_FOUND                                            ((NTSTATUS)0xC002000B) /**< The object UUID was not found. */
#define RPC_NT_ALREADY_REGISTERED                                          ((NTSTATUS)0xC002000C) /**< The object UUID has already been registered. */
#define RPC_NT_TYPE_ALREADY_REGISTERED                                     ((NTSTATUS)0xC002000D) /**< The type UUID has already been registered. */
#define RPC_NT_ALREADY_LISTENING                                           ((NTSTATUS)0xC002000E) /**< The RPC server is already listening. */
#define RPC_NT_NO_PROTSEQS_REGISTERED                                      ((NTSTATUS)0xC002000F) /**< No protocol sequences have been registered. */
#define RPC_NT_NOT_LISTENING                                               ((NTSTATUS)0xC0020010) /**< The RPC server is not listening. */
#define RPC_NT_UNKNOWN_MGR_TYPE                                            ((NTSTATUS)0xC0020011) /**< The manager type is unknown. */
#define RPC_NT_UNKNOWN_IF                                                  ((NTSTATUS)0xC0020012) /**< The interface is unknown. */
#define RPC_NT_NO_BINDINGS                                                 ((NTSTATUS)0xC0020013) /**< There are no bindings. */
#define RPC_NT_NO_PROTSEQS                                                 ((NTSTATUS)0xC0020014) /**< There are no protocol sequences. */
#define RPC_NT_CANT_CREATE_ENDPOINT                                        ((NTSTATUS)0xC0020015) /**< The endpoint cannot be created. */
#define RPC_NT_OUT_OF_RESOURCES                                            ((NTSTATUS)0xC0020016) /**< Insufficient resources are available to complete this operation. */
#define RPC_NT_SERVER_UNAVAILABLE                                          ((NTSTATUS)0xC0020017) /**< The RPC server is unavailable. */
#define RPC_NT_SERVER_TOO_BUSY                                             ((NTSTATUS)0xC0020018) /**< The RPC server is too busy to complete this operation. */
#define RPC_NT_INVALID_NETWORK_OPTIONS                                     ((NTSTATUS)0xC0020019) /**< The network options are invalid. */
#define RPC_NT_NO_CALL_ACTIVE                                              ((NTSTATUS)0xC002001A) /**< No RPCs are active on this thread. */
#define RPC_NT_CALL_FAILED                                                 ((NTSTATUS)0xC002001B) /**< The RPC failed. */
#define RPC_NT_CALL_FAILED_DNE                                             ((NTSTATUS)0xC002001C) /**< The RPC failed and did not execute. */
#define RPC_NT_PROTOCOL_ERROR                                              ((NTSTATUS)0xC002001D) /**< An RPC protocol error occurred. */
#define RPC_NT_UNSUPPORTED_TRANS_SYN                                       ((NTSTATUS)0xC002001F) /**< The RPC server does not support the transfer syntax. */
#define RPC_NT_UNSUPPORTED_TYPE                                            ((NTSTATUS)0xC0020021) /**< The type UUID is not supported. */
#define RPC_NT_INVALID_TAG                                                 ((NTSTATUS)0xC0020022) /**< The tag is invalid. */
#define RPC_NT_INVALID_BOUND                                               ((NTSTATUS)0xC0020023) /**< The array bounds are invalid. */
#define RPC_NT_NO_ENTRY_NAME                                               ((NTSTATUS)0xC0020024) /**< The binding does not contain an entry name. */
#define RPC_NT_INVALID_NAME_SYNTAX                                         ((NTSTATUS)0xC0020025) /**< The name syntax is invalid. */
#define RPC_NT_UNSUPPORTED_NAME_SYNTAX                                     ((NTSTATUS)0xC0020026) /**< The name syntax is not supported. */
#define RPC_NT_UUID_NO_ADDRESS                                             ((NTSTATUS)0xC0020028) /**< No network address is available to construct a UUID. */
#define RPC_NT_DUPLICATE_ENDPOINT                                          ((NTSTATUS)0xC0020029) /**< The endpoint is a duplicate. */
#define RPC_NT_UNKNOWN_AUTHN_TYPE                                          ((NTSTATUS)0xC002002A) /**< The authentication type is unknown. */
#define RPC_NT_MAX_CALLS_TOO_SMALL                                         ((NTSTATUS)0xC002002B) /**< The maximum number of calls is too small. */
#define RPC_NT_STRING_TOO_LONG                                             ((NTSTATUS)0xC002002C) /**< The string is too long. */
#define RPC_NT_PROTSEQ_NOT_FOUND                                           ((NTSTATUS)0xC002002D) /**< The RPC protocol sequence was not found. */
#define RPC_NT_PROCNUM_OUT_OF_RANGE                                        ((NTSTATUS)0xC002002E) /**< The procedure number is out of range. */
#define RPC_NT_BINDING_HAS_NO_AUTH                                         ((NTSTATUS)0xC002002F) /**< The binding does not contain any authentication information. */
#define RPC_NT_UNKNOWN_AUTHN_SERVICE                                       ((NTSTATUS)0xC0020030) /**< The authentication service is unknown. */
#define RPC_NT_UNKNOWN_AUTHN_LEVEL                                         ((NTSTATUS)0xC0020031) /**< The authentication level is unknown. */
#define RPC_NT_INVALID_AUTH_IDENTITY                                       ((NTSTATUS)0xC0020032) /**< The security context is invalid. */
#define RPC_NT_UNKNOWN_AUTHZ_SERVICE                                       ((NTSTATUS)0xC0020033) /**< The authorization service is unknown. */
#define EPT_NT_INVALID_ENTRY                                               ((NTSTATUS)0xC0020034) /**< The entry is invalid. */
#define EPT_NT_CANT_PERFORM_OP                                             ((NTSTATUS)0xC0020035) /**< The operation cannot be performed. */
#define EPT_NT_NOT_REGISTERED                                              ((NTSTATUS)0xC0020036) /**< No more endpoints are available from the endpoint mapper. */
#define RPC_NT_NOTHING_TO_EXPORT                                           ((NTSTATUS)0xC0020037) /**< No interfaces have been exported. */
#define RPC_NT_INCOMPLETE_NAME                                             ((NTSTATUS)0xC0020038) /**< The entry name is incomplete. */
#define RPC_NT_INVALID_VERS_OPTION                                         ((NTSTATUS)0xC0020039) /**< The version option is invalid. */
#define RPC_NT_NO_MORE_MEMBERS                                             ((NTSTATUS)0xC002003A) /**< There are no more members. */
#define RPC_NT_NOT_ALL_OBJS_UNEXPORTED                                     ((NTSTATUS)0xC002003B) /**< There is nothing to unexport. */
#define RPC_NT_INTERFACE_NOT_FOUND                                         ((NTSTATUS)0xC002003C) /**< The interface was not found. */
#define RPC_NT_ENTRY_ALREADY_EXISTS                                        ((NTSTATUS)0xC002003D) /**< The entry already exists. */
#define RPC_NT_ENTRY_NOT_FOUND                                             ((NTSTATUS)0xC002003E) /**< The entry was not found. */
#define RPC_NT_NAME_SERVICE_UNAVAILABLE                                    ((NTSTATUS)0xC002003F) /**< The name service is unavailable. */
#define RPC_NT_INVALID_NAF_ID                                              ((NTSTATUS)0xC0020040) /**< The network address family is invalid. */
#define RPC_NT_CANNOT_SUPPORT                                              ((NTSTATUS)0xC0020041) /**< The requested operation is not supported. */
#define RPC_NT_NO_CONTEXT_AVAILABLE                                        ((NTSTATUS)0xC0020042) /**< No security context is available to allow impersonation. */
#define RPC_NT_INTERNAL_ERROR                                              ((NTSTATUS)0xC0020043) /**< An internal error occurred in the RPC. */
#define RPC_NT_ZERO_DIVIDE                                                 ((NTSTATUS)0xC0020044) /**< The RPC server attempted to divide an integer by zero. */
#define RPC_NT_ADDRESS_ERROR                                               ((NTSTATUS)0xC0020045) /**< An addressing error occurred in the RPC server. */
#define RPC_NT_FP_DIV_ZERO                                                 ((NTSTATUS)0xC0020046) /**< A floating point operation at the RPC server caused a divide by zero. */
#define RPC_NT_FP_UNDERFLOW                                                ((NTSTATUS)0xC0020047) /**< A floating point underflow occurred at the RPC server. */
#define RPC_NT_FP_OVERFLOW                                                 ((NTSTATUS)0xC0020048) /**< A floating point overflow occurred at the RPC server. */
#define RPC_NT_CALL_IN_PROGRESS                                            ((NTSTATUS)0xC0020049) /**< An RPC is already in progress for this thread. */
#define RPC_NT_NO_MORE_BINDINGS                                            ((NTSTATUS)0xC002004A) /**< There are no more bindings. */
#define RPC_NT_GROUP_MEMBER_NOT_FOUND                                      ((NTSTATUS)0xC002004B) /**< The group member was not found. */
#define EPT_NT_CANT_CREATE                                                 ((NTSTATUS)0xC002004C) /**< The endpoint mapper database entry could not be created. */
#define RPC_NT_INVALID_OBJECT                                              ((NTSTATUS)0xC002004D) /**< The object UUID is the nil UUID. */
#define RPC_NT_NO_INTERFACES                                               ((NTSTATUS)0xC002004F) /**< No interfaces have been registered. */
#define RPC_NT_CALL_CANCELLED                                              ((NTSTATUS)0xC0020050) /**< The RPC was canceled. */
#define RPC_NT_BINDING_INCOMPLETE                                          ((NTSTATUS)0xC0020051) /**< The binding handle does not contain all the required information. */
#define RPC_NT_COMM_FAILURE                                                ((NTSTATUS)0xC0020052) /**< A communications failure occurred during an RPC. */
#define RPC_NT_UNSUPPORTED_AUTHN_LEVEL                                     ((NTSTATUS)0xC0020053) /**< The requested authentication level is not supported. */
#define RPC_NT_NO_PRINC_NAME                                               ((NTSTATUS)0xC0020054) /**< No principal name was registered. */
#define RPC_NT_NOT_RPC_ERROR                                               ((NTSTATUS)0xC0020055) /**< The error specified is not a valid Windows RPC error code. */
#define RPC_NT_SEC_PKG_ERROR                                               ((NTSTATUS)0xC0020057) /**< A security package-specific error occurred. */
#define RPC_NT_NOT_CANCELLED                                               ((NTSTATUS)0xC0020058) /**< The thread was not canceled. */
#define RPC_NT_INVALID_ASYNC_HANDLE                                        ((NTSTATUS)0xC0020062) /**< Invalid asynchronous RPC handle. */
#define RPC_NT_INVALID_ASYNC_CALL                                          ((NTSTATUS)0xC0020063) /**< Invalid asynchronous RPC call handle for this operation. */
#define RPC_NT_PROXY_ACCESS_DENIED                                         ((NTSTATUS)0xC0020064) /**< Access to the HTTP proxy is denied. */
#define RPC_NT_NO_MORE_ENTRIES                                             ((NTSTATUS)0xC0030001) /**< The list of RPC servers available for auto-handle binding has been exhausted. */
#define RPC_NT_SS_CHAR_TRANS_OPEN_FAIL                                     ((NTSTATUS)0xC0030002) /**< The file designated by DCERPCCHARTRANS cannot be opened. */
#define RPC_NT_SS_CHAR_TRANS_SHORT_FILE                                    ((NTSTATUS)0xC0030003) /**< The file containing the character translation table has fewer than 512 bytes. */
#define RPC_NT_SS_IN_NULL_CONTEXT                                          ((NTSTATUS)0xC0030004) /**< A null context handle is passed as an [in] parameter. */
#define RPC_NT_SS_CONTEXT_MISMATCH                                         ((NTSTATUS)0xC0030005) /**< The context handle does not match any known context handles. */
#define RPC_NT_SS_CONTEXT_DAMAGED                                          ((NTSTATUS)0xC0030006) /**< The context handle changed during a call. */
#define RPC_NT_SS_HANDLES_MISMATCH                                         ((NTSTATUS)0xC0030007) /**< The binding handles passed to an RPC do not match. */
#define RPC_NT_SS_CANNOT_GET_CALL_HANDLE                                   ((NTSTATUS)0xC0030008) /**< The stub is unable to get the call handle. */
#define RPC_NT_NULL_REF_POINTER                                            ((NTSTATUS)0xC0030009) /**< A null reference pointer was passed to the stub. */
#define RPC_NT_ENUM_VALUE_OUT_OF_RANGE                                     ((NTSTATUS)0xC003000A) /**< The enumeration value is out of range. */
#define RPC_NT_BYTE_COUNT_TOO_SMALL                                        ((NTSTATUS)0xC003000B) /**< The byte count is too small. */
#define RPC_NT_BAD_STUB_DATA                                               ((NTSTATUS)0xC003000C) /**< The stub received bad data. */
#define RPC_NT_INVALID_ES_ACTION                                           ((NTSTATUS)0xC0030059) /**< Invalid operation on the encoding/decoding handle. */
#define RPC_NT_WRONG_ES_VERSION                                            ((NTSTATUS)0xC003005A) /**< Incompatible version of the serializing package. */
#define RPC_NT_WRONG_STUB_VERSION                                          ((NTSTATUS)0xC003005B) /**< Incompatible version of the RPC stub. */
#define RPC_NT_INVALID_PIPE_OBJECT                                         ((NTSTATUS)0xC003005C) /**< The RPC pipe object is invalid or corrupt. */
#define RPC_NT_INVALID_PIPE_OPERATION                                      ((NTSTATUS)0xC003005D) /**< An invalid operation was attempted on an RPC pipe object. */
#define RPC_NT_WRONG_PIPE_VERSION                                          ((NTSTATUS)0xC003005E) /**< Unsupported RPC pipe version. */
#define RPC_NT_PIPE_CLOSED                                                 ((NTSTATUS)0xC003005F) /**< The RPC pipe object has already been closed. */
#define RPC_NT_PIPE_DISCIPLINE_ERROR                                       ((NTSTATUS)0xC0030060) /**< The RPC call completed before all pipes were processed. */
#define RPC_NT_PIPE_EMPTY                                                  ((NTSTATUS)0xC0030061) /**< No more data is available from the RPC pipe. */
#define STATUS_PNP_BAD_MPS_TABLE                                           ((NTSTATUS)0xC0040035) /**< A device is missing in the system BIOS MPS table. This device will not be used. Contact your system vendor for a system BIOS update. */
#define STATUS_PNP_TRANSLATION_FAILED                                      ((NTSTATUS)0xC0040036) /**< A translator failed to translate resources. */
#define STATUS_PNP_IRQ_TRANSLATION_FAILED                                  ((NTSTATUS)0xC0040037) /**< An IRQ translator failed to translate resources. */
#define STATUS_PNP_INVALID_ID                                              ((NTSTATUS)0xC0040038) /**< Driver %2 returned an invalid ID for a child device (%3). */
#define STATUS_IO_REISSUE_AS_CACHED                                        ((NTSTATUS)0xC0040039) /**< Reissue the given operation as a cached I/O operation */
#define STATUS_CTX_WINSTATION_NAME_INVALID                                 ((NTSTATUS)0xC00A0001) /**< Session name %1 is invalid. */
#define STATUS_CTX_INVALID_PD                                              ((NTSTATUS)0xC00A0002) /**< The protocol driver %1 is invalid. */
#define STATUS_CTX_PD_NOT_FOUND                                            ((NTSTATUS)0xC00A0003) /**< The protocol driver %1 was not found in the system path. */
#define STATUS_CTX_CLOSE_PENDING                                           ((NTSTATUS)0xC00A0006) /**< A close operation is pending on the terminal connection. */
#define STATUS_CTX_NO_OUTBUF                                               ((NTSTATUS)0xC00A0007) /**< No free output buffers are available. */
#define STATUS_CTX_MODEM_INF_NOT_FOUND                                     ((NTSTATUS)0xC00A0008) /**< The MODEM.INF file was not found. */
#define STATUS_CTX_INVALID_MODEMNAME                                       ((NTSTATUS)0xC00A0009) /**< The modem (%1) was not found in the MODEM.INF file. */
#define STATUS_CTX_RESPONSE_ERROR                                          ((NTSTATUS)0xC00A000A) /**< The modem did not accept the command sent to it. Verify that the configured modem name matches the attached modem. */
#define STATUS_CTX_MODEM_RESPONSE_TIMEOUT                                  ((NTSTATUS)0xC00A000B) /**< The modem did not respond to the command sent to it. Verify that the modem cable is properly attached and the modem is turned on. */
#define STATUS_CTX_MODEM_RESPONSE_NO_CARRIER                               ((NTSTATUS)0xC00A000C) /**< Carrier detection has failed or the carrier has been dropped due to disconnection. */
#define STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE                              ((NTSTATUS)0xC00A000D) /**< A dial tone was not detected within the required time. Verify that the phone cable is properly attached and functional. */
#define STATUS_CTX_MODEM_RESPONSE_BUSY                                     ((NTSTATUS)0xC00A000E) /**< A busy signal was detected at a remote site on callback. */
#define STATUS_CTX_MODEM_RESPONSE_VOICE                                    ((NTSTATUS)0xC00A000F) /**< A voice was detected at a remote site on callback. */
#define STATUS_CTX_TD_ERROR                                                ((NTSTATUS)0xC00A0010) /**< Transport driver error. */
#define STATUS_CTX_LICENSE_CLIENT_INVALID                                  ((NTSTATUS)0xC00A0012) /**< The client you are using is not licensed to use this system. Your logon request is denied. */
#define STATUS_CTX_LICENSE_NOT_AVAILABLE                                   ((NTSTATUS)0xC00A0013) /**< The system has reached its licensed logon limit. Try again later. */
#define STATUS_CTX_LICENSE_EXPIRED                                         ((NTSTATUS)0xC00A0014) /**< The system license has expired. Your logon request is denied. */
#define STATUS_CTX_WINSTATION_NOT_FOUND                                    ((NTSTATUS)0xC00A0015) /**< The specified session cannot be found. */
#define STATUS_CTX_WINSTATION_NAME_COLLISION                               ((NTSTATUS)0xC00A0016) /**< The specified session name is already in use. */
#define STATUS_CTX_WINSTATION_BUSY                                         ((NTSTATUS)0xC00A0017) /**< The requested operation cannot be completed because the terminal connection is currently processing a connect, disconnect, reset, or delete operation. */
#define STATUS_CTX_BAD_VIDEO_MODE                                          ((NTSTATUS)0xC00A0018) /**< An attempt has been made to connect to a session whose video mode is not supported by the current client. */
#define STATUS_CTX_GRAPHICS_INVALID                                        ((NTSTATUS)0xC00A0022) /**< The application attempted to enable DOS graphics mode. DOS graphics mode is not supported. */
#define STATUS_CTX_NOT_CONSOLE                                             ((NTSTATUS)0xC00A0024) /**< The requested operation can be performed only on the system console. This is most often the result of a driver or system DLL requiring direct console access. */
#define STATUS_CTX_CLIENT_QUERY_TIMEOUT                                    ((NTSTATUS)0xC00A0026) /**< The client failed to respond to the server connect message. */
#define STATUS_CTX_CONSOLE_DISCONNECT                                      ((NTSTATUS)0xC00A0027) /**< Disconnecting the console session is not supported. */
#define STATUS_CTX_CONSOLE_CONNECT                                         ((NTSTATUS)0xC00A0028) /**< Reconnecting a disconnected session to the console is not supported. */
#define STATUS_CTX_SHADOW_DENIED                                           ((NTSTATUS)0xC00A002A) /**< The request to control another session remotely was denied. */
#define STATUS_CTX_WINSTATION_ACCESS_DENIED                                ((NTSTATUS)0xC00A002B) /**< A process has requested access to a session, but has not been granted those access rights. */
#define STATUS_CTX_INVALID_WD                                              ((NTSTATUS)0xC00A002E) /**< The terminal connection driver %1 is invalid. */
#define STATUS_CTX_WD_NOT_FOUND                                            ((NTSTATUS)0xC00A002F) /**< The terminal connection driver %1 was not found in the system path. */
#define STATUS_CTX_SHADOW_INVALID                                          ((NTSTATUS)0xC00A0030) /**< The requested session cannot be controlled remotely. You cannot control your own session, a session that is trying to control your session, a session that has no user logged on, or other sessions from the console. */
#define STATUS_CTX_SHADOW_DISABLED                                         ((NTSTATUS)0xC00A0031) /**< The requested session is not configured to allow remote control. */
#define STATUS_RDP_PROTOCOL_ERROR                                          ((NTSTATUS)0xC00A0032) /**< The RDP protocol component %2 detected an error in the protocol stream and has disconnected the client. */
#define STATUS_CTX_CLIENT_LICENSE_NOT_SET                                  ((NTSTATUS)0xC00A0033) /**< Your request to connect to this terminal server has been rejected. Your terminal server client license number has not been entered for this copy of the terminal client. Contact your system administrator for help in entering a valid, unique license number for this terminal server client. Click OK to continue. */
#define STATUS_CTX_CLIENT_LICENSE_IN_USE                                   ((NTSTATUS)0xC00A0034) /**< Your request to connect to this terminal server has been rejected. Your terminal server client license number is currently being used by another user. Contact your system administrator to obtain a new copy of the terminal server client with a valid, unique license number. Click OK to continue. */
#define STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE                             ((NTSTATUS)0xC00A0035) /**< The remote control of the console was terminated because the display mode was changed. Changing the display mode in a remote control session is not supported. */
#define STATUS_CTX_SHADOW_NOT_RUNNING                                      ((NTSTATUS)0xC00A0036) /**< Remote control could not be terminated because the specified session is not currently being remotely controlled. */
#define STATUS_CTX_LOGON_DISABLED                                          ((NTSTATUS)0xC00A0037) /**< Your interactive logon privilege has been disabled. Contact your system administrator. */
#define STATUS_CTX_SECURITY_LAYER_ERROR                                    ((NTSTATUS)0xC00A0038) /**< The terminal server security layer detected an error in the protocol stream and has disconnected the client. */
#define STATUS_TS_INCOMPATIBLE_SESSIONS                                    ((NTSTATUS)0xC00A0039) /**< The target session is incompatible with the current session. */
#define STATUS_MUI_FILE_NOT_FOUND                                          ((NTSTATUS)0xC00B0001) /**< The resource loader failed to find an MUI file. */
#define STATUS_MUI_INVALID_FILE                                            ((NTSTATUS)0xC00B0002) /**< The resource loader failed to load an MUI file because the file failed to pass validation. */
#define STATUS_MUI_INVALID_RC_CONFIG                                       ((NTSTATUS)0xC00B0003) /**< The RC manifest is corrupted with garbage data, is an unsupported version, or is missing a required item. */
#define STATUS_MUI_INVALID_LOCALE_NAME                                     ((NTSTATUS)0xC00B0004) /**< The RC manifest has an invalid culture name. */
#define STATUS_MUI_INVALID_ULTIMATEFALLBACK_NAME                           ((NTSTATUS)0xC00B0005) /**< The RC manifest has and invalid ultimate fallback name. */
#define STATUS_MUI_FILE_NOT_LOADED                                         ((NTSTATUS)0xC00B0006) /**< The resource loader cache does not have a loaded MUI entry. */
#define STATUS_RESOURCE_ENUM_USER_STOP                                     ((NTSTATUS)0xC00B0007) /**< The user stopped resource enumeration. */
#define STATUS_CLUSTER_INVALID_NODE                                        ((NTSTATUS)0xC0130001) /**< The cluster node is not valid. */
#define STATUS_CLUSTER_NODE_EXISTS                                         ((NTSTATUS)0xC0130002) /**< The cluster node already exists. */
#define STATUS_CLUSTER_JOIN_IN_PROGRESS                                    ((NTSTATUS)0xC0130003) /**< A node is in the process of joining the cluster. */
#define STATUS_CLUSTER_NODE_NOT_FOUND                                      ((NTSTATUS)0xC0130004) /**< The cluster node was not found. */
#define STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND                                ((NTSTATUS)0xC0130005) /**< The cluster local node information was not found. */
#define STATUS_CLUSTER_NETWORK_EXISTS                                      ((NTSTATUS)0xC0130006) /**< The cluster network already exists. */
#define STATUS_CLUSTER_NETWORK_NOT_FOUND                                   ((NTSTATUS)0xC0130007) /**< The cluster network was not found. */
#define STATUS_CLUSTER_NETINTERFACE_EXISTS                                 ((NTSTATUS)0xC0130008) /**< The cluster network interface already exists. */
#define STATUS_CLUSTER_NETINTERFACE_NOT_FOUND                              ((NTSTATUS)0xC0130009) /**< The cluster network interface was not found. */
#define STATUS_CLUSTER_INVALID_REQUEST                                     ((NTSTATUS)0xC013000A) /**< The cluster request is not valid for this object. */
#define STATUS_CLUSTER_INVALID_NETWORK_PROVIDER                            ((NTSTATUS)0xC013000B) /**< The cluster network provider is not valid. */
#define STATUS_CLUSTER_NODE_DOWN                                           ((NTSTATUS)0xC013000C) /**< The cluster node is down. */
#define STATUS_CLUSTER_NODE_UNREACHABLE                                    ((NTSTATUS)0xC013000D) /**< The cluster node is not reachable. */
#define STATUS_CLUSTER_NODE_NOT_MEMBER                                     ((NTSTATUS)0xC013000E) /**< The cluster node is not a member of the cluster. */
#define STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS                                ((NTSTATUS)0xC013000F) /**< A cluster join operation is not in progress. */
#define STATUS_CLUSTER_INVALID_NETWORK                                     ((NTSTATUS)0xC0130010) /**< The cluster network is not valid. */
#define STATUS_CLUSTER_NO_NET_ADAPTERS                                     ((NTSTATUS)0xC0130011) /**< No network adapters are available. */
#define STATUS_CLUSTER_NODE_UP                                             ((NTSTATUS)0xC0130012) /**< The cluster node is up. */
#define STATUS_CLUSTER_NODE_PAUSED                                         ((NTSTATUS)0xC0130013) /**< The cluster node is paused. */
#define STATUS_CLUSTER_NODE_NOT_PAUSED                                     ((NTSTATUS)0xC0130014) /**< The cluster node is not paused. */
#define STATUS_CLUSTER_NO_SECURITY_CONTEXT                                 ((NTSTATUS)0xC0130015) /**< No cluster security context is available. */
#define STATUS_CLUSTER_NETWORK_NOT_INTERNAL                                ((NTSTATUS)0xC0130016) /**< The cluster network is not configured for internal cluster communication. */
#define STATUS_CLUSTER_POISONED                                            ((NTSTATUS)0xC0130017) /**< The cluster node has been poisoned. */
#define STATUS_ACPI_INVALID_OPCODE                                         ((NTSTATUS)0xC0140001) /**< An attempt was made to run an invalid AML opcode. */
#define STATUS_ACPI_STACK_OVERFLOW                                         ((NTSTATUS)0xC0140002) /**< The AML interpreter stack has overflowed. */
#define STATUS_ACPI_ASSERT_FAILED                                          ((NTSTATUS)0xC0140003) /**< An inconsistent state has occurred. */
#define STATUS_ACPI_INVALID_INDEX                                          ((NTSTATUS)0xC0140004) /**< An attempt was made to access an array outside its bounds. */
#define STATUS_ACPI_INVALID_ARGUMENT                                       ((NTSTATUS)0xC0140005) /**< A required argument was not specified. */
#define STATUS_ACPI_FATAL                                                  ((NTSTATUS)0xC0140006) /**< A fatal error has occurred. */
#define STATUS_ACPI_INVALID_SUPERNAME                                      ((NTSTATUS)0xC0140007) /**< An invalid SuperName was specified. */
#define STATUS_ACPI_INVALID_ARGTYPE                                        ((NTSTATUS)0xC0140008) /**< An argument with an incorrect type was specified. */
#define STATUS_ACPI_INVALID_OBJTYPE                                        ((NTSTATUS)0xC0140009) /**< An object with an incorrect type was specified. */
#define STATUS_ACPI_INVALID_TARGETTYPE                                     ((NTSTATUS)0xC014000A) /**< A target with an incorrect type was specified. */
#define STATUS_ACPI_INCORRECT_ARGUMENT_COUNT                               ((NTSTATUS)0xC014000B) /**< An incorrect number of arguments was specified. */
#define STATUS_ACPI_ADDRESS_NOT_MAPPED                                     ((NTSTATUS)0xC014000C) /**< An address failed to translate. */
#define STATUS_ACPI_INVALID_EVENTTYPE                                      ((NTSTATUS)0xC014000D) /**< An incorrect event type was specified. */
#define STATUS_ACPI_HANDLER_COLLISION                                      ((NTSTATUS)0xC014000E) /**< A handler for the target already exists. */
#define STATUS_ACPI_INVALID_DATA                                           ((NTSTATUS)0xC014000F) /**< Invalid data for the target was specified. */
#define STATUS_ACPI_INVALID_REGION                                         ((NTSTATUS)0xC0140010) /**< An invalid region for the target was specified. */
#define STATUS_ACPI_INVALID_ACCESS_SIZE                                    ((NTSTATUS)0xC0140011) /**< An attempt was made to access a field outside the defined range. */
#define STATUS_ACPI_ACQUIRE_GLOBAL_LOCK                                    ((NTSTATUS)0xC0140012) /**< The global system lock could not be acquired. */
#define STATUS_ACPI_ALREADY_INITIALIZED                                    ((NTSTATUS)0xC0140013) /**< An attempt was made to reinitialize the ACPI subsystem. */
#define STATUS_ACPI_NOT_INITIALIZED                                        ((NTSTATUS)0xC0140014) /**< The ACPI subsystem has not been initialized. */
#define STATUS_ACPI_INVALID_MUTEX_LEVEL                                    ((NTSTATUS)0xC0140015) /**< An incorrect mutex was specified. */
#define STATUS_ACPI_MUTEX_NOT_OWNED                                        ((NTSTATUS)0xC0140016) /**< The mutex is not currently owned. */
#define STATUS_ACPI_MUTEX_NOT_OWNER                                        ((NTSTATUS)0xC0140017) /**< An attempt was made to access the mutex by a process that was not the owner. */
#define STATUS_ACPI_RS_ACCESS                                              ((NTSTATUS)0xC0140018) /**< An error occurred during an access to region space. */
#define STATUS_ACPI_INVALID_TABLE                                          ((NTSTATUS)0xC0140019) /**< An attempt was made to use an incorrect table. */
#define STATUS_ACPI_REG_HANDLER_FAILED                                     ((NTSTATUS)0xC0140020) /**< The registration of an ACPI event failed. */
#define STATUS_ACPI_POWER_REQUEST_FAILED                                   ((NTSTATUS)0xC0140021) /**< An ACPI power object failed to transition state. */
#define STATUS_SXS_SECTION_NOT_FOUND                                       ((NTSTATUS)0xC0150001) /**< The requested section is not present in the activation context. */
#define STATUS_SXS_CANT_GEN_ACTCTX                                         ((NTSTATUS)0xC0150002) /**< Windows was unble to process the application binding information. Refer to the system event log for further information. */
#define STATUS_SXS_INVALID_ACTCTXDATA_FORMAT                               ((NTSTATUS)0xC0150003) /**< The application binding data format is invalid. */
#define STATUS_SXS_ASSEMBLY_NOT_FOUND                                      ((NTSTATUS)0xC0150004) /**< The referenced assembly is not installed on the system. */
#define STATUS_SXS_MANIFEST_FORMAT_ERROR                                   ((NTSTATUS)0xC0150005) /**< The manifest file does not begin with the required tag and format information. */
#define STATUS_SXS_MANIFEST_PARSE_ERROR                                    ((NTSTATUS)0xC0150006) /**< The manifest file contains one or more syntax errors. */
#define STATUS_SXS_ACTIVATION_CONTEXT_DISABLED                             ((NTSTATUS)0xC0150007) /**< The application attempted to activate a disabled activation context. */
#define STATUS_SXS_KEY_NOT_FOUND                                           ((NTSTATUS)0xC0150008) /**< The requested lookup key was not found in any active activation context. */
#define STATUS_SXS_VERSION_CONFLICT                                        ((NTSTATUS)0xC0150009) /**< A component version required by the application conflicts with another component version that is already active. */
#define STATUS_SXS_WRONG_SECTION_TYPE                                      ((NTSTATUS)0xC015000A) /**< The type requested activation context section does not match the query API used. */
#define STATUS_SXS_THREAD_QUERIES_DISABLED                                 ((NTSTATUS)0xC015000B) /**< Lack of system resources has required isolated activation to be disabled for the current thread of execution. */
#define STATUS_SXS_ASSEMBLY_MISSING                                        ((NTSTATUS)0xC015000C) /**< The referenced assembly could not be found. */
#define STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET                             ((NTSTATUS)0xC015000E) /**< An attempt to set the process default activation context failed because the process default activation context was already set. */
#define STATUS_SXS_EARLY_DEACTIVATION                                      ((NTSTATUS)0xC015000F) /**< The activation context being deactivated is not the most recently activated one. */
#define STATUS_SXS_INVALID_DEACTIVATION                                    ((NTSTATUS)0xC0150010) /**< The activation context being deactivated is not active for the current thread of execution. */
#define STATUS_SXS_MULTIPLE_DEACTIVATION                                   ((NTSTATUS)0xC0150011) /**< The activation context being deactivated has already been deactivated. */
#define STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY                 ((NTSTATUS)0xC0150012) /**< The activation context of the system default assembly could not be generated. */
#define STATUS_SXS_PROCESS_TERMINATION_REQUESTED                           ((NTSTATUS)0xC0150013) /**< A component used by the isolation facility has requested that the process be terminated. */
#define STATUS_SXS_CORRUPT_ACTIVATION_STACK                                ((NTSTATUS)0xC0150014) /**< The activation context activation stack for the running thread of execution is corrupt. */
#define STATUS_SXS_CORRUPTION                                              ((NTSTATUS)0xC0150015) /**< The application isolation metadata for this process or thread has become corrupt. */
#define STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE                        ((NTSTATUS)0xC0150016) /**< The value of an attribute in an identity is not within the legal range. */
#define STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME                         ((NTSTATUS)0xC0150017) /**< The name of an attribute in an identity is not within the legal range. */
#define STATUS_SXS_IDENTITY_DUPLICATE_ATTRIBUTE                            ((NTSTATUS)0xC0150018) /**< An identity contains two definitions for the same attribute. */
#define STATUS_SXS_IDENTITY_PARSE_ERROR                                    ((NTSTATUS)0xC0150019) /**< The identity string is malformed. This might be due to a trailing comma, more than two unnamed attributes, a missing attribute name, or a missing attribute value. */
#define STATUS_SXS_COMPONENT_STORE_CORRUPT                                 ((NTSTATUS)0xC015001A) /**< The component store has become corrupted. */
#define STATUS_SXS_FILE_HASH_MISMATCH                                      ((NTSTATUS)0xC015001B) /**< A component's file does not match the verification information present in the component manifest. */
#define STATUS_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT           ((NTSTATUS)0xC015001C) /**< The identities of the manifests are identical, but their contents are different. */
#define STATUS_SXS_IDENTITIES_DIFFERENT                                    ((NTSTATUS)0xC015001D) /**< The component identities are different. */
#define STATUS_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT                            ((NTSTATUS)0xC015001E) /**< The assembly is not a deployment. */
#define STATUS_SXS_FILE_NOT_PART_OF_ASSEMBLY                               ((NTSTATUS)0xC015001F) /**< The file is not a part of the assembly. */
#define STATUS_ADVANCED_INSTALLER_FAILED                                   ((NTSTATUS)0xC0150020) /**< An advanced installer failed during setup or servicing. */
#define STATUS_XML_ENCODING_MISMATCH                                       ((NTSTATUS)0xC0150021) /**< The character encoding in the XML declaration did not match the encoding used in the document. */
#define STATUS_SXS_MANIFEST_TOO_BIG                                        ((NTSTATUS)0xC0150022) /**< The size of the manifest exceeds the maximum allowed. */
#define STATUS_SXS_SETTING_NOT_REGISTERED                                  ((NTSTATUS)0xC0150023) /**< The setting is not registered. */
#define STATUS_SXS_TRANSACTION_CLOSURE_INCOMPLETE                          ((NTSTATUS)0xC0150024) /**< One or more required transaction members are not present. */
#define STATUS_SMI_PRIMITIVE_INSTALLER_FAILED                              ((NTSTATUS)0xC0150025) /**< The SMI primitive installer failed during setup or servicing. */
#define STATUS_GENERIC_COMMAND_FAILED                                      ((NTSTATUS)0xC0150026) /**< A generic command executable returned a result that indicates failure. */
#define STATUS_SXS_FILE_HASH_MISSING                                       ((NTSTATUS)0xC0150027) /**< A component is missing file verification information in its manifest. */
#define STATUS_TRANSACTIONAL_CONFLICT                                      ((NTSTATUS)0xC0190001) /**< The function attempted to use a name that is reserved for use by another transaction. */
#define STATUS_INVALID_TRANSACTION                                         ((NTSTATUS)0xC0190002) /**< The transaction handle associated with this operation is invalid. */
#define STATUS_TRANSACTION_NOT_ACTIVE                                      ((NTSTATUS)0xC0190003) /**< The requested operation was made in the context of a transaction that is no longer active. */
#define STATUS_TM_INITIALIZATION_FAILED                                    ((NTSTATUS)0xC0190004) /**< The transaction manager was unable to be successfully initialized. Transacted operations are not supported. */
#define STATUS_RM_NOT_ACTIVE                                               ((NTSTATUS)0xC0190005) /**< Transaction support within the specified file system resource manager was not started or was shut down due to an error. */
#define STATUS_RM_METADATA_CORRUPT                                         ((NTSTATUS)0xC0190006) /**< The metadata of the resource manager has been corrupted. The resource manager will not function. */
#define STATUS_TRANSACTION_NOT_JOINED                                      ((NTSTATUS)0xC0190007) /**< The resource manager attempted to prepare a transaction that it has not successfully joined. */
#define STATUS_DIRECTORY_NOT_RM                                            ((NTSTATUS)0xC0190008) /**< The specified directory does not contain a file system resource manager. */
#define STATUS_TRANSACTIONS_UNSUPPORTED_REMOTE                             ((NTSTATUS)0xC019000A) /**< The remote server or share does not support transacted file operations. */
#define STATUS_LOG_RESIZE_INVALID_SIZE                                     ((NTSTATUS)0xC019000B) /**< The requested log size for the file system resource manager is invalid. */
#define STATUS_REMOTE_FILE_VERSION_MISMATCH                                ((NTSTATUS)0xC019000C) /**< The remote server sent mismatching version number or Fid for a file opened with transactions. */
#define STATUS_CRM_PROTOCOL_ALREADY_EXISTS                                 ((NTSTATUS)0xC019000F) /**< The resource manager tried to register a protocol that already exists. */
#define STATUS_TRANSACTION_PROPAGATION_FAILED                              ((NTSTATUS)0xC0190010) /**< The attempt to propagate the transaction failed. */
#define STATUS_CRM_PROTOCOL_NOT_FOUND                                      ((NTSTATUS)0xC0190011) /**< The requested propagation protocol was not registered as a CRM. */
#define STATUS_TRANSACTION_SUPERIOR_EXISTS                                 ((NTSTATUS)0xC0190012) /**< The transaction object already has a superior enlistment, and the caller attempted an operation that would have created a new superior. Only a single superior enlistment is allowed. */
#define STATUS_TRANSACTION_REQUEST_NOT_VALID                               ((NTSTATUS)0xC0190013) /**< The requested operation is not valid on the transaction object in its current state. */
#define STATUS_TRANSACTION_NOT_REQUESTED                                   ((NTSTATUS)0xC0190014) /**< The caller has called a response API, but the response is not expected because the transaction manager did not issue the corresponding request to the caller. */
#define STATUS_TRANSACTION_ALREADY_ABORTED                                 ((NTSTATUS)0xC0190015) /**< It is too late to perform the requested operation, because the transaction has already been aborted. */
#define STATUS_TRANSACTION_ALREADY_COMMITTED                               ((NTSTATUS)0xC0190016) /**< It is too late to perform the requested operation, because the transaction has already been committed. */
#define STATUS_TRANSACTION_INVALID_MARSHALL_BUFFER                         ((NTSTATUS)0xC0190017) /**< The buffer passed in to NtPushTransaction or NtPullTransaction is not in a valid format. */
#define STATUS_CURRENT_TRANSACTION_NOT_VALID                               ((NTSTATUS)0xC0190018) /**< The current transaction context associated with the thread is not a valid handle to a transaction object. */
#define STATUS_LOG_GROWTH_FAILED                                           ((NTSTATUS)0xC0190019) /**< An attempt to create space in the transactional resource manager's log failed. The failure status has been recorded in the event log. */
#define STATUS_OBJECT_NO_LONGER_EXISTS                                     ((NTSTATUS)0xC0190021) /**< The object (file, stream, or link) that corresponds to the handle has been deleted by a transaction savepoint rollback. */
#define STATUS_STREAM_MINIVERSION_NOT_FOUND                                ((NTSTATUS)0xC0190022) /**< The specified file miniversion was not found for this transacted file open. */
#define STATUS_STREAM_MINIVERSION_NOT_VALID                                ((NTSTATUS)0xC0190023) /**< The specified file miniversion was found but has been invalidated. The most likely cause is a transaction savepoint rollback. */
#define STATUS_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION         ((NTSTATUS)0xC0190024) /**< A miniversion can be opened only in the context of the transaction that created it. */
#define STATUS_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT                    ((NTSTATUS)0xC0190025) /**< It is not possible to open a miniversion with modify access. */
#define STATUS_CANT_CREATE_MORE_STREAM_MINIVERSIONS                        ((NTSTATUS)0xC0190026) /**< It is not possible to create any more miniversions for this stream. */
#define STATUS_HANDLE_NO_LONGER_VALID                                      ((NTSTATUS)0xC0190028) /**< The handle has been invalidated by a transaction. The most likely cause is the presence of memory mapping on a file or an open handle when the transaction ended or rolled back to savepoint. */
#define STATUS_LOG_CORRUPTION_DETECTED                                     ((NTSTATUS)0xC0190030) /**< The log data is corrupt. */
#define STATUS_RM_DISCONNECTED                                             ((NTSTATUS)0xC0190032) /**< The transaction outcome is unavailable because the resource manager responsible for it is disconnected. */
#define STATUS_ENLISTMENT_NOT_SUPERIOR                                     ((NTSTATUS)0xC0190033) /**< The request was rejected because the enlistment in question is not a superior enlistment. */
#define STATUS_FILE_IDENTITY_NOT_PERSISTENT                                ((NTSTATUS)0xC0190036) /**< The file cannot be opened in a transaction because its identity depends on the outcome of an unresolved transaction. */
#define STATUS_CANT_BREAK_TRANSACTIONAL_DEPENDENCY                         ((NTSTATUS)0xC0190037) /**< The operation cannot be performed because another transaction is depending on this property not changing. */
#define STATUS_CANT_CROSS_RM_BOUNDARY                                      ((NTSTATUS)0xC0190038) /**< The operation would involve a single file with two transactional resource managers and is, therefore, not allowed. */
#define STATUS_TXF_DIR_NOT_EMPTY                                           ((NTSTATUS)0xC0190039) /**< The $Txf directory must be empty for this operation to succeed. */
#define STATUS_INDOUBT_TRANSACTIONS_EXIST                                  ((NTSTATUS)0xC019003A) /**< The operation would leave a transactional resource manager in an inconsistent state and is therefore not allowed. */
#define STATUS_TM_VOLATILE                                                 ((NTSTATUS)0xC019003B) /**< The operation could not be completed because the transaction manager does not have a log. */
#define STATUS_ROLLBACK_TIMER_EXPIRED                                      ((NTSTATUS)0xC019003C) /**< A rollback could not be scheduled because a previously scheduled rollback has already executed or been queued for execution. */
#define STATUS_TXF_ATTRIBUTE_CORRUPT                                       ((NTSTATUS)0xC019003D) /**< The transactional metadata attribute on the file or directory %hs is corrupt and unreadable. */
#define STATUS_EFS_NOT_ALLOWED_IN_TRANSACTION                              ((NTSTATUS)0xC019003E) /**< The encryption operation could not be completed because a transaction is active. */
#define STATUS_TRANSACTIONAL_OPEN_NOT_ALLOWED                              ((NTSTATUS)0xC019003F) /**< This object is not allowed to be opened in a transaction. */
#define STATUS_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE                       ((NTSTATUS)0xC0190040) /**< Memory mapping (creating a mapped section) a remote file under a transaction is not supported. */
#define STATUS_TRANSACTION_REQUIRED_PROMOTION                              ((NTSTATUS)0xC0190043) /**< Promotion was required to allow the resource manager to enlist, but the transaction was set to disallow it. */
#define STATUS_CANNOT_EXECUTE_FILE_IN_TRANSACTION                          ((NTSTATUS)0xC0190044) /**< This file is open for modification in an unresolved transaction and can be opened for execute only by a transacted reader. */
#define STATUS_TRANSACTIONS_NOT_FROZEN                                     ((NTSTATUS)0xC0190045) /**< The request to thaw frozen transactions was ignored because transactions were not previously frozen. */
#define STATUS_TRANSACTION_FREEZE_IN_PROGRESS                              ((NTSTATUS)0xC0190046) /**< Transactions cannot be frozen because a freeze is already in progress. */
#define STATUS_NOT_SNAPSHOT_VOLUME                                         ((NTSTATUS)0xC0190047) /**< The target volume is not a snapshot volume. This operation is valid only on a volume mounted as a snapshot. */
#define STATUS_NO_SAVEPOINT_WITH_OPEN_FILES                                ((NTSTATUS)0xC0190048) /**< The savepoint operation failed because files are open on the transaction, which is not permitted. */
#define STATUS_SPARSE_NOT_ALLOWED_IN_TRANSACTION                           ((NTSTATUS)0xC0190049) /**< The sparse operation could not be completed because a transaction is active on the file. */
#define STATUS_TM_IDENTITY_MISMATCH                                        ((NTSTATUS)0xC019004A) /**< The call to create a transaction manager object failed because the Tm Identity that is stored in the log file does not match the Tm Identity that was passed in as an argument. */
#define STATUS_FLOATED_SECTION                                             ((NTSTATUS)0xC019004B) /**< I/O was attempted on a section object that has been floated as a result of a transaction ending. There is no valid data. */
#define STATUS_CANNOT_ACCEPT_TRANSACTED_WORK                               ((NTSTATUS)0xC019004C) /**< The transactional resource manager cannot currently accept transacted work due to a transient condition, such as low resources. */
#define STATUS_CANNOT_ABORT_TRANSACTIONS                                   ((NTSTATUS)0xC019004D) /**< The transactional resource manager had too many transactions outstanding that could not be aborted. The transactional resource manager has been shut down. */
#define STATUS_TRANSACTION_NOT_FOUND                                       ((NTSTATUS)0xC019004E) /**< The specified transaction was unable to be opened because it was not found. */
#define STATUS_RESOURCEMANAGER_NOT_FOUND                                   ((NTSTATUS)0xC019004F) /**< The specified resource manager was unable to be opened because it was not found. */
#define STATUS_ENLISTMENT_NOT_FOUND                                        ((NTSTATUS)0xC0190050) /**< The specified enlistment was unable to be opened because it was not found. */
#define STATUS_TRANSACTIONMANAGER_NOT_FOUND                                ((NTSTATUS)0xC0190051) /**< The specified transaction manager was unable to be opened because it was not found. */
#define STATUS_TRANSACTIONMANAGER_NOT_ONLINE                               ((NTSTATUS)0xC0190052) /**< The specified resource manager was unable to create an enlistment because its associated transaction manager is not online. */
#define STATUS_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION                  ((NTSTATUS)0xC0190053) /**< The specified transaction manager was unable to create the objects contained in its log file in the Ob namespace. Therefore, the transaction manager was unable to recover. */
#define STATUS_TRANSACTION_NOT_ROOT                                        ((NTSTATUS)0xC0190054) /**< The call to create a superior enlistment on this transaction object could not be completed because the transaction object specified for the enlistment is a subordinate branch of the transaction. Only the root of the transaction can be enlisted as a superior. */
#define STATUS_TRANSACTION_OBJECT_EXPIRED                                  ((NTSTATUS)0xC0190055) /**< Because the associated transaction manager or resource manager has been closed, the handle is no longer valid. */
#define STATUS_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION                      ((NTSTATUS)0xC0190056) /**< The compression operation could not be completed because a transaction is active on the file. */
#define STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED                           ((NTSTATUS)0xC0190057) /**< The specified operation could not be performed on this superior enlistment because the enlistment was not created with the corresponding completion response in the NotificationMask. */
#define STATUS_TRANSACTION_RECORD_TOO_LONG                                 ((NTSTATUS)0xC0190058) /**< The specified operation could not be performed because the record to be logged was too long. This can occur because either there are too many enlistments on this transaction or the combined RecoveryInformation being logged on behalf of those enlistments is too long. */
#define STATUS_NO_LINK_TRACKING_IN_TRANSACTION                             ((NTSTATUS)0xC0190059) /**< The link-tracking operation could not be completed because a transaction is active. */
#define STATUS_OPERATION_NOT_SUPPORTED_IN_TRANSACTION                      ((NTSTATUS)0xC019005A) /**< This operation cannot be performed in a transaction. */
#define STATUS_TRANSACTION_INTEGRITY_VIOLATED                              ((NTSTATUS)0xC019005B) /**< The kernel transaction manager had to abort or forget the transaction because it blocked forward progress. */
#define STATUS_EXPIRED_HANDLE                                              ((NTSTATUS)0xC0190060) /**< The handle is no longer properly associated with its transaction.  It might have been opened in a transactional resource manager that was subsequently forced to restart.  Please close the handle and open a new one. */
#define STATUS_TRANSACTION_NOT_ENLISTED                                    ((NTSTATUS)0xC0190061) /**< The specified operation could not be performed because the resource manager is not enlisted in the transaction. */
#define STATUS_LOG_SECTOR_INVALID                                          ((NTSTATUS)0xC01A0001) /**< The log service found an invalid log sector. */
#define STATUS_LOG_SECTOR_PARITY_INVALID                                   ((NTSTATUS)0xC01A0002) /**< The log service encountered a log sector with invalid block parity. */
#define STATUS_LOG_SECTOR_REMAPPED                                         ((NTSTATUS)0xC01A0003) /**< The log service encountered a remapped log sector. */
#define STATUS_LOG_BLOCK_INCOMPLETE                                        ((NTSTATUS)0xC01A0004) /**< The log service encountered a partial or incomplete log block. */
#define STATUS_LOG_INVALID_RANGE                                           ((NTSTATUS)0xC01A0005) /**< The log service encountered an attempt to access data outside the active log range. */
#define STATUS_LOG_BLOCKS_EXHAUSTED                                        ((NTSTATUS)0xC01A0006) /**< The log service user-log marshaling buffers are exhausted. */
#define STATUS_LOG_READ_CONTEXT_INVALID                                    ((NTSTATUS)0xC01A0007) /**< The log service encountered an attempt to read from a marshaling area with an invalid read context. */
#define STATUS_LOG_RESTART_INVALID                                         ((NTSTATUS)0xC01A0008) /**< The log service encountered an invalid log restart area. */
#define STATUS_LOG_BLOCK_VERSION                                           ((NTSTATUS)0xC01A0009) /**< The log service encountered an invalid log block version. */
#define STATUS_LOG_BLOCK_INVALID                                           ((NTSTATUS)0xC01A000A) /**< The log service encountered an invalid log block. */
#define STATUS_LOG_READ_MODE_INVALID                                       ((NTSTATUS)0xC01A000B) /**< The log service encountered an attempt to read the log with an invalid read mode. */
#define STATUS_LOG_METADATA_CORRUPT                                        ((NTSTATUS)0xC01A000D) /**< The log service encountered a corrupted metadata file. */
#define STATUS_LOG_METADATA_INVALID                                        ((NTSTATUS)0xC01A000E) /**< The log service encountered a metadata file that could not be created by the log file system. */
#define STATUS_LOG_METADATA_INCONSISTENT                                   ((NTSTATUS)0xC01A000F) /**< The log service encountered a metadata file with inconsistent data. */
#define STATUS_LOG_RESERVATION_INVALID                                     ((NTSTATUS)0xC01A0010) /**< The log service encountered an attempt to erroneously allocate or dispose reservation space. */
#define STATUS_LOG_CANT_DELETE                                             ((NTSTATUS)0xC01A0011) /**< The log service cannot delete the log file or the file system container. */
#define STATUS_LOG_CONTAINER_LIMIT_EXCEEDED                                ((NTSTATUS)0xC01A0012) /**< The log service has reached the maximum allowable containers allocated to a log file. */
#define STATUS_LOG_START_OF_LOG                                            ((NTSTATUS)0xC01A0013) /**< The log service has attempted to read or write backward past the start of the log. */
#define STATUS_LOG_POLICY_ALREADY_INSTALLED                                ((NTSTATUS)0xC01A0014) /**< The log policy could not be installed because a policy of the same type is already present. */
#define STATUS_LOG_POLICY_NOT_INSTALLED                                    ((NTSTATUS)0xC01A0015) /**< The log policy in question was not installed at the time of the request. */
#define STATUS_LOG_POLICY_INVALID                                          ((NTSTATUS)0xC01A0016) /**< The installed set of policies on the log is invalid. */
#define STATUS_LOG_POLICY_CONFLICT                                         ((NTSTATUS)0xC01A0017) /**< A policy on the log in question prevented the operation from completing. */
#define STATUS_LOG_PINNED_ARCHIVE_TAIL                                     ((NTSTATUS)0xC01A0018) /**< The log space cannot be reclaimed because the log is pinned by the archive tail. */
#define STATUS_LOG_RECORD_NONEXISTENT                                      ((NTSTATUS)0xC01A0019) /**< The log record is not a record in the log file. */
#define STATUS_LOG_RECORDS_RESERVED_INVALID                                ((NTSTATUS)0xC01A001A) /**< The number of reserved log records or the adjustment of the number of reserved log records is invalid. */
#define STATUS_LOG_SPACE_RESERVED_INVALID                                  ((NTSTATUS)0xC01A001B) /**< The reserved log space or the adjustment of the log space is invalid. */
#define STATUS_LOG_TAIL_INVALID                                            ((NTSTATUS)0xC01A001C) /**< A new or existing archive tail or the base of the active log is invalid. */
#define STATUS_LOG_FULL                                                    ((NTSTATUS)0xC01A001D) /**< The log space is exhausted. */
#define STATUS_LOG_MULTIPLEXED                                             ((NTSTATUS)0xC01A001E) /**< The log is multiplexed; no direct writes to the physical log are allowed. */
#define STATUS_LOG_DEDICATED                                               ((NTSTATUS)0xC01A001F) /**< The operation failed because the log is dedicated. */
#define STATUS_LOG_ARCHIVE_NOT_IN_PROGRESS                                 ((NTSTATUS)0xC01A0020) /**< The operation requires an archive context. */
#define STATUS_LOG_ARCHIVE_IN_PROGRESS                                     ((NTSTATUS)0xC01A0021) /**< Log archival is in progress. */
#define STATUS_LOG_EPHEMERAL                                               ((NTSTATUS)0xC01A0022) /**< The operation requires a nonephemeral log, but the log is ephemeral. */
#define STATUS_LOG_NOT_ENOUGH_CONTAINERS                                   ((NTSTATUS)0xC01A0023) /**< The log must have at least two containers before it can be read from or written to. */
#define STATUS_LOG_CLIENT_ALREADY_REGISTERED                               ((NTSTATUS)0xC01A0024) /**< A log client has already registered on the stream. */
#define STATUS_LOG_CLIENT_NOT_REGISTERED                                   ((NTSTATUS)0xC01A0025) /**< A log client has not been registered on the stream. */
#define STATUS_LOG_FULL_HANDLER_IN_PROGRESS                                ((NTSTATUS)0xC01A0026) /**< A request has already been made to handle the log full condition. */
#define STATUS_LOG_CONTAINER_READ_FAILED                                   ((NTSTATUS)0xC01A0027) /**< The log service encountered an error when attempting to read from a log container. */
#define STATUS_LOG_CONTAINER_WRITE_FAILED                                  ((NTSTATUS)0xC01A0028) /**< The log service encountered an error when attempting to write to a log container. */
#define STATUS_LOG_CONTAINER_OPEN_FAILED                                   ((NTSTATUS)0xC01A0029) /**< The log service encountered an error when attempting to open a log container. */
#define STATUS_LOG_CONTAINER_STATE_INVALID                                 ((NTSTATUS)0xC01A002A) /**< The log service encountered an invalid container state when attempting a requested action. */
#define STATUS_LOG_STATE_INVALID                                           ((NTSTATUS)0xC01A002B) /**< The log service is not in the correct state to perform a requested action. */
#define STATUS_LOG_PINNED                                                  ((NTSTATUS)0xC01A002C) /**< The log space cannot be reclaimed because the log is pinned. */
#define STATUS_LOG_METADATA_FLUSH_FAILED                                   ((NTSTATUS)0xC01A002D) /**< The log metadata flush failed. */
#define STATUS_LOG_INCONSISTENT_SECURITY                                   ((NTSTATUS)0xC01A002E) /**< Security on the log and its containers is inconsistent. */
#define STATUS_LOG_APPENDED_FLUSH_FAILED                                   ((NTSTATUS)0xC01A002F) /**< Records were appended to the log or reservation changes were made, but the log could not be flushed. */
#define STATUS_LOG_PINNED_RESERVATION                                      ((NTSTATUS)0xC01A0030) /**< The log is pinned due to reservation consuming most of the log space. Free some reserved records to make space available. */
#define STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD                            ((NTSTATUS)0xC01B00EA) /**< {Display Driver Stopped Responding} The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality. The next time you reboot the computer, a dialog box will allow you to upload data about this failure to Microsoft. */
#define STATUS_FLT_NO_HANDLER_DEFINED                                      ((NTSTATUS)0xC01C0001) /**< A handler was not defined by the filter for this operation. */
#define STATUS_FLT_CONTEXT_ALREADY_DEFINED                                 ((NTSTATUS)0xC01C0002) /**< A context is already defined for this object. */
#define STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST                            ((NTSTATUS)0xC01C0003) /**< Asynchronous requests are not valid for this operation. */
#define STATUS_FLT_DISALLOW_FAST_IO                                        ((NTSTATUS)0xC01C0004) /**< This is an internal error code used by the filter manager to determine if a fast I/O operation should be forced down the input/output request packet (IRP) path. Minifilters should never return this value. */
#define STATUS_FLT_INVALID_NAME_REQUEST                                    ((NTSTATUS)0xC01C0005) /**< An invalid name request was made. The name requested cannot be retrieved at this time. */
#define STATUS_FLT_NOT_SAFE_TO_POST_OPERATION                              ((NTSTATUS)0xC01C0006) /**< Posting this operation to a worker thread for further processing is not safe at this time because it could lead to a system deadlock. */
#define STATUS_FLT_NOT_INITIALIZED                                         ((NTSTATUS)0xC01C0007) /**< The Filter Manager was not initialized when a filter tried to register. Make sure that the Filter Manager is loaded as a driver. */
#define STATUS_FLT_FILTER_NOT_READY                                        ((NTSTATUS)0xC01C0008) /**< The filter is not ready for attachment to volumes because it has not finished initializing (FltStartFiltering has not been called). */
#define STATUS_FLT_POST_OPERATION_CLEANUP                                  ((NTSTATUS)0xC01C0009) /**< The filter must clean up any operation-specific context at this time because it is being removed from the system before the operation is completed by the lower drivers. */
#define STATUS_FLT_INTERNAL_ERROR                                          ((NTSTATUS)0xC01C000A) /**< The Filter Manager had an internal error from which it cannot recover; therefore, the operation has failed. This is usually the result of a filter returning an invalid value from a pre-operation callback. */
#define STATUS_FLT_DELETING_OBJECT                                         ((NTSTATUS)0xC01C000B) /**< The object specified for this action is in the process of being deleted; therefore, the action requested cannot be completed at this time. */
#define STATUS_FLT_MUST_BE_NONPAGED_POOL                                   ((NTSTATUS)0xC01C000C) /**< A nonpaged pool must be used for this type of context. */
#define STATUS_FLT_DUPLICATE_ENTRY                                         ((NTSTATUS)0xC01C000D) /**< A duplicate handler definition has been provided for an operation. */
#define STATUS_FLT_CBDQ_DISABLED                                           ((NTSTATUS)0xC01C000E) /**< The callback data queue has been disabled. */
#define STATUS_FLT_DO_NOT_ATTACH                                           ((NTSTATUS)0xC01C000F) /**< Do not attach the filter to the volume at this time. */
#define STATUS_FLT_DO_NOT_DETACH                                           ((NTSTATUS)0xC01C0010) /**< Do not detach the filter from the volume at this time. */
#define STATUS_FLT_INSTANCE_ALTITUDE_COLLISION                             ((NTSTATUS)0xC01C0011) /**< An instance already exists at this altitude on the volume specified. */
#define STATUS_FLT_INSTANCE_NAME_COLLISION                                 ((NTSTATUS)0xC01C0012) /**< An instance already exists with this name on the volume specified. */
#define STATUS_FLT_FILTER_NOT_FOUND                                        ((NTSTATUS)0xC01C0013) /**< The system could not find the filter specified. */
#define STATUS_FLT_VOLUME_NOT_FOUND                                        ((NTSTATUS)0xC01C0014) /**< The system could not find the volume specified. */
#define STATUS_FLT_INSTANCE_NOT_FOUND                                      ((NTSTATUS)0xC01C0015) /**< The system could not find the instance specified. */
#define STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND                            ((NTSTATUS)0xC01C0016) /**< No registered context allocation definition was found for the given request. */
#define STATUS_FLT_INVALID_CONTEXT_REGISTRATION                            ((NTSTATUS)0xC01C0017) /**< An invalid parameter was specified during context registration. */
#define STATUS_FLT_NAME_CACHE_MISS                                         ((NTSTATUS)0xC01C0018) /**< The name requested was not found in the Filter Manager name cache and could not be retrieved from the file system. */
#define STATUS_FLT_NO_DEVICE_OBJECT                                        ((NTSTATUS)0xC01C0019) /**< The requested device object does not exist for the given volume. */
#define STATUS_FLT_VOLUME_ALREADY_MOUNTED                                  ((NTSTATUS)0xC01C001A) /**< The specified volume is already mounted. */
#define STATUS_FLT_ALREADY_ENLISTED                                        ((NTSTATUS)0xC01C001B) /**< The specified transaction context is already enlisted in a transaction. */
#define STATUS_FLT_CONTEXT_ALREADY_LINKED                                  ((NTSTATUS)0xC01C001C) /**< The specified context is already attached to another object. */
#define STATUS_FLT_NO_WAITER_FOR_REPLY                                     ((NTSTATUS)0xC01C0020) /**< No waiter is present for the filter's reply to this message. */
#define STATUS_MONITOR_NO_DESCRIPTOR                                       ((NTSTATUS)0xC01D0001) /**< A monitor descriptor could not be obtained. */
#define STATUS_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT                           ((NTSTATUS)0xC01D0002) /**< This release does not support the format of the obtained monitor descriptor. */
#define STATUS_MONITOR_INVALID_DESCRIPTOR_CHECKSUM                         ((NTSTATUS)0xC01D0003) /**< The checksum of the obtained monitor descriptor is invalid. */
#define STATUS_MONITOR_INVALID_STANDARD_TIMING_BLOCK                       ((NTSTATUS)0xC01D0004) /**< The monitor descriptor contains an invalid standard timing block. */
#define STATUS_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED                   ((NTSTATUS)0xC01D0005) /**< WMI data-block registration failed for one of the MSMonitorClass WMI subclasses. */
#define STATUS_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK                  ((NTSTATUS)0xC01D0006) /**< The provided monitor descriptor block is either corrupted or does not contain the monitor's detailed serial number. */
#define STATUS_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK                  ((NTSTATUS)0xC01D0007) /**< The provided monitor descriptor block is either corrupted or does not contain the monitor's user-friendly name. */
#define STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA                             ((NTSTATUS)0xC01D0008) /**< There is no monitor descriptor data at the specified (offset or size) region. */
#define STATUS_MONITOR_INVALID_DETAILED_TIMING_BLOCK                       ((NTSTATUS)0xC01D0009) /**< The monitor descriptor contains an invalid detailed timing block. */
#define STATUS_MONITOR_INVALID_MANUFACTURE_DATE                            ((NTSTATUS)0xC01D000A) /**< Monitor descriptor contains invalid manufacture date. */
#define STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER                           ((NTSTATUS)0xC01E0000) /**< Exclusive mode ownership is needed to create an unmanaged primary allocation. */
#define STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER                            ((NTSTATUS)0xC01E0001) /**< The driver needs more DMA buffer space to complete the requested operation. */
#define STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER                            ((NTSTATUS)0xC01E0002) /**< The specified display adapter handle is invalid. */
#define STATUS_GRAPHICS_ADAPTER_WAS_RESET                                  ((NTSTATUS)0xC01E0003) /**< The specified display adapter and all of its state have been reset. */
#define STATUS_GRAPHICS_INVALID_DRIVER_MODEL                               ((NTSTATUS)0xC01E0004) /**< The driver stack does not match the expected driver model. */
#define STATUS_GRAPHICS_PRESENT_MODE_CHANGED                               ((NTSTATUS)0xC01E0005) /**< Present happened but ended up into the changed desktop mode. */
#define STATUS_GRAPHICS_PRESENT_OCCLUDED                                   ((NTSTATUS)0xC01E0006) /**< Nothing to present due to desktop occlusion. */
#define STATUS_GRAPHICS_PRESENT_DENIED                                     ((NTSTATUS)0xC01E0007) /**< Not able to present due to denial of desktop access. */
#define STATUS_GRAPHICS_CANNOTCOLORCONVERT                                 ((NTSTATUS)0xC01E0008) /**< Not able to present with color conversion. */
#define STATUS_GRAPHICS_PRESENT_REDIRECTION_DISABLED                       ((NTSTATUS)0xC01E000B) /**< Present redirection is disabled (desktop windowing management subsystem is off). */
#define STATUS_GRAPHICS_PRESENT_UNOCCLUDED                                 ((NTSTATUS)0xC01E000C) /**< Previous exclusive VidPn source owner has released its ownership */
#define STATUS_GRAPHICS_NO_VIDEO_MEMORY                                    ((NTSTATUS)0xC01E0100) /**< Not enough video memory is available to complete the operation. */
#define STATUS_GRAPHICS_CANT_LOCK_MEMORY                                   ((NTSTATUS)0xC01E0101) /**< Could not probe and lock the underlying memory of an allocation. */
#define STATUS_GRAPHICS_ALLOCATION_BUSY                                    ((NTSTATUS)0xC01E0102) /**< The allocation is currently busy. */
#define STATUS_GRAPHICS_TOO_MANY_REFERENCES                                ((NTSTATUS)0xC01E0103) /**< An object being referenced has already reached the maximum reference count and cannot be referenced further. */
#define STATUS_GRAPHICS_TRY_AGAIN_LATER                                    ((NTSTATUS)0xC01E0104) /**< A problem could not be solved due to an existing condition. Try again later. */
#define STATUS_GRAPHICS_TRY_AGAIN_NOW                                      ((NTSTATUS)0xC01E0105) /**< A problem could not be solved due to an existing condition. Try again now. */
#define STATUS_GRAPHICS_ALLOCATION_INVALID                                 ((NTSTATUS)0xC01E0106) /**< The allocation is invalid. */
#define STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE                   ((NTSTATUS)0xC01E0107) /**< No more unswizzling apertures are currently available. */
#define STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED                   ((NTSTATUS)0xC01E0108) /**< The current allocation cannot be unswizzled by an aperture. */
#define STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION                       ((NTSTATUS)0xC01E0109) /**< The request failed because a pinned allocation cannot be evicted. */
#define STATUS_GRAPHICS_INVALID_ALLOCATION_USAGE                           ((NTSTATUS)0xC01E0110) /**< The allocation cannot be used from its current segment location for the specified operation. */
#define STATUS_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION                      ((NTSTATUS)0xC01E0111) /**< A locked allocation cannot be used in the current command buffer. */
#define STATUS_GRAPHICS_ALLOCATION_CLOSED                                  ((NTSTATUS)0xC01E0112) /**< The allocation being referenced has been closed permanently. */
#define STATUS_GRAPHICS_INVALID_ALLOCATION_INSTANCE                        ((NTSTATUS)0xC01E0113) /**< An invalid allocation instance is being referenced. */
#define STATUS_GRAPHICS_INVALID_ALLOCATION_HANDLE                          ((NTSTATUS)0xC01E0114) /**< An invalid allocation handle is being referenced. */
#define STATUS_GRAPHICS_WRONG_ALLOCATION_DEVICE                            ((NTSTATUS)0xC01E0115) /**< The allocation being referenced does not belong to the current device. */
#define STATUS_GRAPHICS_ALLOCATION_CONTENT_LOST                            ((NTSTATUS)0xC01E0116) /**< The specified allocation lost its content. */
#define STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE                            ((NTSTATUS)0xC01E0200) /**< A GPU exception was detected on the given device. The device cannot be scheduled. */
#define STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY                             ((NTSTATUS)0xC01E0300) /**< The specified VidPN topology is invalid. */
#define STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED                       ((NTSTATUS)0xC01E0301) /**< The specified VidPN topology is valid but is not supported by this model of the display adapter. */
#define STATUS_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED             ((NTSTATUS)0xC01E0302) /**< The specified VidPN topology is valid but is not currently supported by the display adapter due to allocation of its resources. */
#define STATUS_GRAPHICS_INVALID_VIDPN                                      ((NTSTATUS)0xC01E0303) /**< The specified VidPN handle is invalid. */
#define STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE                       ((NTSTATUS)0xC01E0304) /**< The specified video present source is invalid. */
#define STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET                       ((NTSTATUS)0xC01E0305) /**< The specified video present target is invalid. */
#define STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED                       ((NTSTATUS)0xC01E0306) /**< The specified VidPN modality is not supported (for example, at least two of the pinned modes are not co-functional). */
#define STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET                        ((NTSTATUS)0xC01E0308) /**< The specified VidPN source mode set is invalid. */
#define STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET                        ((NTSTATUS)0xC01E0309) /**< The specified VidPN target mode set is invalid. */
#define STATUS_GRAPHICS_INVALID_FREQUENCY                                  ((NTSTATUS)0xC01E030A) /**< The specified video signal frequency is invalid. */
#define STATUS_GRAPHICS_INVALID_ACTIVE_REGION                              ((NTSTATUS)0xC01E030B) /**< The specified video signal active region is invalid. */
#define STATUS_GRAPHICS_INVALID_TOTAL_REGION                               ((NTSTATUS)0xC01E030C) /**< The specified video signal total region is invalid. */
#define STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE                  ((NTSTATUS)0xC01E0310) /**< The specified video present source mode is invalid. */
#define STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE                  ((NTSTATUS)0xC01E0311) /**< The specified video present target mode is invalid. */
#define STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET                     ((NTSTATUS)0xC01E0312) /**< The pinned mode must remain in the set on the VidPN's co-functional modality enumeration. */
#define STATUS_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY                           ((NTSTATUS)0xC01E0313) /**< The specified video present path is already in the VidPN's topology. */
#define STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET                            ((NTSTATUS)0xC01E0314) /**< The specified mode is already in the mode set. */
#define STATUS_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET                      ((NTSTATUS)0xC01E0315) /**< The specified video present source set is invalid. */
#define STATUS_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET                      ((NTSTATUS)0xC01E0316) /**< The specified video present target set is invalid. */
#define STATUS_GRAPHICS_SOURCE_ALREADY_IN_SET                              ((NTSTATUS)0xC01E0317) /**< The specified video present source is already in the video present source set. */
#define STATUS_GRAPHICS_TARGET_ALREADY_IN_SET                              ((NTSTATUS)0xC01E0318) /**< The specified video present target is already in the video present target set. */
#define STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH                         ((NTSTATUS)0xC01E0319) /**< The specified VidPN present path is invalid. */
#define STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY                      ((NTSTATUS)0xC01E031A) /**< The miniport has no recommendation for augmenting the specified VidPN's topology. */
#define STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET                  ((NTSTATUS)0xC01E031B) /**< The specified monitor frequency range set is invalid. */
#define STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE                     ((NTSTATUS)0xC01E031C) /**< The specified monitor frequency range is invalid. */
#define STATUS_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET                          ((NTSTATUS)0xC01E031D) /**< The specified frequency range is not in the specified monitor frequency range set. */
#define STATUS_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET                      ((NTSTATUS)0xC01E031F) /**< The specified frequency range is already in the specified monitor frequency range set. */
#define STATUS_GRAPHICS_STALE_MODESET                                      ((NTSTATUS)0xC01E0320) /**< The specified mode set is stale. Reacquire the new mode set. */
#define STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET                      ((NTSTATUS)0xC01E0321) /**< The specified monitor source mode set is invalid. */
#define STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE                        ((NTSTATUS)0xC01E0322) /**< The specified monitor source mode is invalid. */
#define STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN                    ((NTSTATUS)0xC01E0323) /**< The miniport does not have a recommendation regarding the request to provide a functional VidPN given the current display adapter configuration. */
#define STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE                             ((NTSTATUS)0xC01E0324) /**< The ID of the specified mode is being used by another mode in the set. */
#define STATUS_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION    ((NTSTATUS)0xC01E0325) /**< The system failed to determine a mode that is supported by both the display adapter and the monitor connected to it. */
#define STATUS_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES            ((NTSTATUS)0xC01E0326) /**< The number of video present targets must be greater than or equal to the number of video present sources. */
#define STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY                               ((NTSTATUS)0xC01E0327) /**< The specified present path is not in the VidPN's topology. */
#define STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE              ((NTSTATUS)0xC01E0328) /**< The display adapter must have at least one video present source. */
#define STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET              ((NTSTATUS)0xC01E0329) /**< The display adapter must have at least one video present target. */
#define STATUS_GRAPHICS_INVALID_MONITORDESCRIPTORSET                       ((NTSTATUS)0xC01E032A) /**< The specified monitor descriptor set is invalid. */
#define STATUS_GRAPHICS_INVALID_MONITORDESCRIPTOR                          ((NTSTATUS)0xC01E032B) /**< The specified monitor descriptor is invalid. */
#define STATUS_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET                       ((NTSTATUS)0xC01E032C) /**< The specified descriptor is not in the specified monitor descriptor set. */
#define STATUS_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET                   ((NTSTATUS)0xC01E032D) /**< The specified descriptor is already in the specified monitor descriptor set. */
#define STATUS_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE                ((NTSTATUS)0xC01E032E) /**< The ID of the specified monitor descriptor is being used by another descriptor in the set. */
#define STATUS_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE                   ((NTSTATUS)0xC01E032F) /**< The specified video present target subset type is invalid. */
#define STATUS_GRAPHICS_RESOURCES_NOT_RELATED                              ((NTSTATUS)0xC01E0330) /**< Two or more of the specified resources are not related to each other, as defined by the interface semantics. */
#define STATUS_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE                           ((NTSTATUS)0xC01E0331) /**< The ID of the specified video present source is being used by another source in the set. */
#define STATUS_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE                           ((NTSTATUS)0xC01E0332) /**< The ID of the specified video present target is being used by another target in the set. */
#define STATUS_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET                          ((NTSTATUS)0xC01E0333) /**< The specified VidPN source cannot be used because there is no available VidPN target to connect it to. */
#define STATUS_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER       ((NTSTATUS)0xC01E0334) /**< The newly arrived monitor could not be associated with a display adapter. */
#define STATUS_GRAPHICS_NO_VIDPNMGR                                        ((NTSTATUS)0xC01E0335) /**< The particular display adapter does not have an associated VidPN manager. */
#define STATUS_GRAPHICS_NO_ACTIVE_VIDPN                                    ((NTSTATUS)0xC01E0336) /**< The VidPN manager of the particular display adapter does not have an active VidPN. */
#define STATUS_GRAPHICS_STALE_VIDPN_TOPOLOGY                               ((NTSTATUS)0xC01E0337) /**< The specified VidPN topology is stale; obtain the new topology. */
#define STATUS_GRAPHICS_MONITOR_NOT_CONNECTED                              ((NTSTATUS)0xC01E0338) /**< No monitor is connected on the specified video present target. */
#define STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY                             ((NTSTATUS)0xC01E0339) /**< The specified source is not part of the specified VidPN's topology. */
#define STATUS_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE                        ((NTSTATUS)0xC01E033A) /**< The specified primary surface size is invalid. */
#define STATUS_GRAPHICS_INVALID_VISIBLEREGION_SIZE                         ((NTSTATUS)0xC01E033B) /**< The specified visible region size is invalid. */
#define STATUS_GRAPHICS_INVALID_STRIDE                                     ((NTSTATUS)0xC01E033C) /**< The specified stride is invalid. */
#define STATUS_GRAPHICS_INVALID_PIXELFORMAT                                ((NTSTATUS)0xC01E033D) /**< The specified pixel format is invalid. */
#define STATUS_GRAPHICS_INVALID_COLORBASIS                                 ((NTSTATUS)0xC01E033E) /**< The specified color basis is invalid. */
#define STATUS_GRAPHICS_INVALID_PIXELVALUEACCESSMODE                       ((NTSTATUS)0xC01E033F) /**< The specified pixel value access mode is invalid. */
#define STATUS_GRAPHICS_TARGET_NOT_IN_TOPOLOGY                             ((NTSTATUS)0xC01E0340) /**< The specified target is not part of the specified VidPN's topology. */
#define STATUS_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT                 ((NTSTATUS)0xC01E0341) /**< Failed to acquire the display mode management interface. */
#define STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE                                ((NTSTATUS)0xC01E0342) /**< The specified VidPN source is already owned by a DMM client and cannot be used until that client releases it. */
#define STATUS_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN                           ((NTSTATUS)0xC01E0343) /**< The specified VidPN is active and cannot be accessed. */
#define STATUS_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL                    ((NTSTATUS)0xC01E0344) /**< The specified VidPN's present path importance ordinal is invalid. */
#define STATUS_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION       ((NTSTATUS)0xC01E0345) /**< The specified VidPN's present path content geometry transformation is invalid. */
#define STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED ((NTSTATUS)0xC01E0346) /**< The specified content geometry transformation is not supported on the respective VidPN present path. */
#define STATUS_GRAPHICS_INVALID_GAMMA_RAMP                                 ((NTSTATUS)0xC01E0347) /**< The specified gamma ramp is invalid. */
#define STATUS_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED                           ((NTSTATUS)0xC01E0348) /**< The specified gamma ramp is not supported on the respective VidPN present path. */
#define STATUS_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED                        ((NTSTATUS)0xC01E0349) /**< Multisampling is not supported on the respective VidPN present path. */
#define STATUS_GRAPHICS_MODE_NOT_IN_MODESET                                ((NTSTATUS)0xC01E034A) /**< The specified mode is not in the specified mode set. */
#define STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON       ((NTSTATUS)0xC01E034D) /**< The specified VidPN topology recommendation reason is invalid. */
#define STATUS_GRAPHICS_INVALID_PATH_CONTENT_TYPE                          ((NTSTATUS)0xC01E034E) /**< The specified VidPN present path content type is invalid. */
#define STATUS_GRAPHICS_INVALID_COPYPROTECTION_TYPE                        ((NTSTATUS)0xC01E034F) /**< The specified VidPN present path copy protection type is invalid. */
#define STATUS_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS                  ((NTSTATUS)0xC01E0350) /**< Only one unassigned mode set can exist at any one time for a particular VidPN source or target. */
#define STATUS_GRAPHICS_INVALID_SCANLINE_ORDERING                          ((NTSTATUS)0xC01E0352) /**< The specified scan line ordering type is invalid. */
#define STATUS_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED                       ((NTSTATUS)0xC01E0353) /**< The topology changes are not allowed for the specified VidPN. */
#define STATUS_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS                   ((NTSTATUS)0xC01E0354) /**< All available importance ordinals are being used in the specified topology. */
#define STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT                        ((NTSTATUS)0xC01E0355) /**< The specified primary surface has a different private-format attribute than the current primary surface. */
#define STATUS_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM                     ((NTSTATUS)0xC01E0356) /**< The specified mode-pruning algorithm is invalid. */
#define STATUS_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN                  ((NTSTATUS)0xC01E0357) /**< The specified monitor-capability origin is invalid. */
#define STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT          ((NTSTATUS)0xC01E0358) /**< The specified monitor-frequency range constraint is invalid. */
#define STATUS_GRAPHICS_MAX_NUM_PATHS_REACHED                              ((NTSTATUS)0xC01E0359) /**< The maximum supported number of present paths has been reached. */
#define STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION                 ((NTSTATUS)0xC01E035A) /**< The miniport requested that augmentation be canceled for the specified source of the specified VidPN's topology. */
#define STATUS_GRAPHICS_INVALID_CLIENT_TYPE                                ((NTSTATUS)0xC01E035B) /**< The specified client type was not recognized. */
#define STATUS_GRAPHICS_CLIENTVIDPN_NOT_SET                                ((NTSTATUS)0xC01E035C) /**< The client VidPN is not set on this adapter (for example, no user mode-initiated mode changes have taken place on this adapter). */
#define STATUS_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED                  ((NTSTATUS)0xC01E0400) /**< The specified display adapter child device already has an external device connected to it. */
#define STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED                     ((NTSTATUS)0xC01E0401) /**< The display adapter child device does not support reporting a descriptor. */
#define STATUS_GRAPHICS_NOT_A_LINKED_ADAPTER                               ((NTSTATUS)0xC01E0430) /**< The display adapter is not linked to any other adapters. */
#define STATUS_GRAPHICS_LEADLINK_NOT_ENUMERATED                            ((NTSTATUS)0xC01E0431) /**< The lead adapter in a linked configuration was not enumerated yet. */
#define STATUS_GRAPHICS_CHAINLINKS_NOT_ENUMERATED                          ((NTSTATUS)0xC01E0432) /**< Some chain adapters in a linked configuration have not yet been enumerated. */
#define STATUS_GRAPHICS_ADAPTER_CHAIN_NOT_READY                            ((NTSTATUS)0xC01E0433) /**< The chain of linked adapters is not ready to start because of an unknown failure. */
#define STATUS_GRAPHICS_CHAINLINKS_NOT_STARTED                             ((NTSTATUS)0xC01E0434) /**< An attempt was made to start a lead link display adapter when the chain links had not yet started. */
#define STATUS_GRAPHICS_CHAINLINKS_NOT_POWERED_ON                          ((NTSTATUS)0xC01E0435) /**< An attempt was made to turn on a lead link display adapter when the chain links were turned off. */
#define STATUS_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE                     ((NTSTATUS)0xC01E0436) /**< The adapter link was found in an inconsistent state. Not all adapters are in an expected PNP/power state. */
#define STATUS_GRAPHICS_NOT_POST_DEVICE_DRIVER                             ((NTSTATUS)0xC01E0438) /**< The driver trying to start is not the same as the driver for the posted display adapter. */
#define STATUS_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED                        ((NTSTATUS)0xC01E043B) /**< An operation is being attempted that requires the display adapter to be in a quiescent state. */
#define STATUS_GRAPHICS_OPM_NOT_SUPPORTED                                  ((NTSTATUS)0xC01E0500) /**< The driver does not support OPM. */
#define STATUS_GRAPHICS_COPP_NOT_SUPPORTED                                 ((NTSTATUS)0xC01E0501) /**< The driver does not support COPP. */
#define STATUS_GRAPHICS_UAB_NOT_SUPPORTED                                  ((NTSTATUS)0xC01E0502) /**< The driver does not support UAB. */
#define STATUS_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS                   ((NTSTATUS)0xC01E0503) /**< The specified encrypted parameters are invalid. */
#define STATUS_GRAPHICS_OPM_PARAMETER_ARRAY_TOO_SMALL                      ((NTSTATUS)0xC01E0504) /**< An array passed to a function cannot hold all of the data that the function wants to put in it. */
#define STATUS_GRAPHICS_OPM_NO_PROTECTED_OUTPUTS_EXIST                     ((NTSTATUS)0xC01E0505) /**< The GDI display device passed to this function does not have any active protected outputs. */
#define STATUS_GRAPHICS_PVP_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME          ((NTSTATUS)0xC01E0506) /**< The PVP cannot find an actual GDI display device that corresponds to the passed-in GDI display device name. */
#define STATUS_GRAPHICS_PVP_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP         ((NTSTATUS)0xC01E0507) /**< This function failed because the GDI display device passed to it was not attached to the Windows desktop. */
#define STATUS_GRAPHICS_PVP_MIRRORING_DEVICES_NOT_SUPPORTED                ((NTSTATUS)0xC01E0508) /**< The PVP does not support mirroring display devices because they do not have any protected outputs. */
#define STATUS_GRAPHICS_OPM_INVALID_POINTER                                ((NTSTATUS)0xC01E050A) /**< The function failed because an invalid pointer parameter was passed to it. A pointer parameter is invalid if it is null, is not correctly aligned, or it points to an invalid address or a kernel mode address. */
#define STATUS_GRAPHICS_OPM_INTERNAL_ERROR                                 ((NTSTATUS)0xC01E050B) /**< An internal error caused an operation to fail. */
#define STATUS_GRAPHICS_OPM_INVALID_HANDLE                                 ((NTSTATUS)0xC01E050C) /**< The function failed because the caller passed in an invalid OPM user-mode handle. */
#define STATUS_GRAPHICS_PVP_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE       ((NTSTATUS)0xC01E050D) /**< This function failed because the GDI device passed to it did not have any monitors associated with it. */
#define STATUS_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH                     ((NTSTATUS)0xC01E050E) /**< A certificate could not be returned because the certificate buffer passed to the function was too small. */
#define STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED                          ((NTSTATUS)0xC01E050F) /**< DxgkDdiOpmCreateProtectedOutput() could not create a protected output because the video present yarget is in spanning mode. */
#define STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED                           ((NTSTATUS)0xC01E0510) /**< DxgkDdiOpmCreateProtectedOutput() could not create a protected output because the video present target is in theater mode. */
#define STATUS_GRAPHICS_PVP_HFS_FAILED                                     ((NTSTATUS)0xC01E0511) /**< The function call failed because the display adapter's hardware functionality scan (HFS) failed to validate the graphics hardware. */
#define STATUS_GRAPHICS_OPM_INVALID_SRM                                    ((NTSTATUS)0xC01E0512) /**< The HDCP SRM passed to this function did not comply with section 5 of the HDCP 1.1 specification. */
#define STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP                   ((NTSTATUS)0xC01E0513) /**< The protected output cannot enable the HDCP system because it does not support it. */
#define STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP                    ((NTSTATUS)0xC01E0514) /**< The protected output cannot enable analog copy protection because it does not support it. */
#define STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA                  ((NTSTATUS)0xC01E0515) /**< The protected output cannot enable the CGMS-A protection technology because it does not support it. */
#define STATUS_GRAPHICS_OPM_HDCP_SRM_NEVER_SET                             ((NTSTATUS)0xC01E0516) /**< DxgkDdiOPMGetInformation() cannot return the version of the SRM being used because the application never successfully passed an SRM to the protected output. */
#define STATUS_GRAPHICS_OPM_RESOLUTION_TOO_HIGH                            ((NTSTATUS)0xC01E0517) /**< DxgkDdiOPMConfigureProtectedOutput() cannot enable the specified output protection technology because the output's screen resolution is too high. */
#define STATUS_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE               ((NTSTATUS)0xC01E0518) /**< DxgkDdiOPMConfigureProtectedOutput() cannot enable HDCP because other physical outputs are using the display adapter's HDCP hardware. */
#define STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_NO_LONGER_EXISTS              ((NTSTATUS)0xC01E051A) /**< The operating system asynchronously destroyed this OPM-protected output because the operating system state changed. This error typically occurs because the monitor PDO associated with this protected output was removed or stopped, the protected output's session became a nonconsole session, or the protected output's desktop became inactive. */
#define STATUS_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS                ((NTSTATUS)0xC01E051B) /**< OPM functions cannot be called when a session is changing its type. Three types of sessions currently exist: console, disconnected, and remote (RDP or ICA). */
#define STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS  ((NTSTATUS)0xC01E051C) /**< The DxgkDdiOPMGetCOPPCompatibleInformation, DxgkDdiOPMGetInformation, or DxgkDdiOPMConfigureProtectedOutput function failed. This error is returned only if a protected output has OPM semantics. DxgkDdiOPMGetCOPPCompatibleInformation always returns this error if a protected output has OPM semantics. DxgkDdiOPMGetInformation returns this error code if the caller requested COPP-specific information. DxgkDdiOPMConfigureProtectedOutput returns this error when the caller tries to use a COPP-specific command. */
#define STATUS_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST                    ((NTSTATUS)0xC01E051D) /**< The DxgkDdiOPMGetInformation and DxgkDdiOPMGetCOPPCompatibleInformation functions return this error code if the passed-in sequence number is not the expected sequence number or the passed-in OMAC value is invalid. */
#define STATUS_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR                          ((NTSTATUS)0xC01E051E) /**< The function failed because an unexpected error occurred inside a display driver. */
#define STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS   ((NTSTATUS)0xC01E051F) /**< The DxgkDdiOPMGetCOPPCompatibleInformation, DxgkDdiOPMGetInformation, or DxgkDdiOPMConfigureProtectedOutput function failed. This error is returned only if a protected output has COPP semantics. DxgkDdiOPMGetCOPPCompatibleInformation returns this error code if the caller requested OPM-specific information. DxgkDdiOPMGetInformation always returns this error if a protected output has COPP semantics. DxgkDdiOPMConfigureProtectedOutput returns this error when the caller tries to use an OPM-specific command. */
#define STATUS_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED                        ((NTSTATUS)0xC01E0520) /**< The DxgkDdiOPMGetCOPPCompatibleInformation and DxgkDdiOPMConfigureProtectedOutput functions return this error if the display driver does not support the DXGKMDT_OPM_GET_ACP_AND_CGMSA_SIGNALING and DXGKMDT_OPM_SET_ACP_AND_CGMSA_SIGNALING GUIDs. */
#define STATUS_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST                  ((NTSTATUS)0xC01E0521) /**< The DxgkDdiOPMConfigureProtectedOutput function returns this error code if the passed-in sequence number is not the expected sequence number or the passed-in OMAC value is invalid. */
#define STATUS_GRAPHICS_I2C_NOT_SUPPORTED                                  ((NTSTATUS)0xC01E0580) /**< The monitor connected to the specified video output does not have an I2C bus. */
#define STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST                          ((NTSTATUS)0xC01E0581) /**< No device on the I2C bus has the specified address. */
#define STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA                        ((NTSTATUS)0xC01E0582) /**< An error occurred while transmitting data to the device on the I2C bus. */
#define STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA                           ((NTSTATUS)0xC01E0583) /**< An error occurred while receiving data from the device on the I2C bus. */
#define STATUS_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED                            ((NTSTATUS)0xC01E0584) /**< The monitor does not support the specified VCP code. */
#define STATUS_GRAPHICS_DDCCI_INVALID_DATA                                 ((NTSTATUS)0xC01E0585) /**< The data received from the monitor is invalid. */
#define STATUS_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE  ((NTSTATUS)0xC01E0586) /**< A function call failed because a monitor returned an invalid timing status byte when the operating system used the DDC/CI get timing report and timing message command to get a timing report from a monitor. */
#define STATUS_GRAPHICS_DDCCI_INVALID_CAPABILITIES_STRING                  ((NTSTATUS)0xC01E0587) /**< A monitor returned a DDC/CI capabilities string that did not comply with the ACCESS.bus 3.0, DDC/CI 1.1, or MCCS 2 Revision 1 specification. */
#define STATUS_GRAPHICS_MCA_INTERNAL_ERROR                                 ((NTSTATUS)0xC01E0588) /**< An internal error caused an operation to fail. */
#define STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND                      ((NTSTATUS)0xC01E0589) /**< An operation failed because a DDC/CI message had an invalid value in its command field. */
#define STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH                       ((NTSTATUS)0xC01E058A) /**< This error occurred because a DDC/CI message had an invalid value in its length field. */
#define STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM                     ((NTSTATUS)0xC01E058B) /**< This error occurred because the value in a DDC/CI message's checksum field did not match the message's computed checksum value. This error implies that the data was corrupted while it was being transmitted from a monitor to a computer. */
#define STATUS_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE                    ((NTSTATUS)0xC01E058C) /**< This function failed because an invalid monitor handle was passed to it. */
#define STATUS_GRAPHICS_MONITOR_NO_LONGER_EXISTS                           ((NTSTATUS)0xC01E058D) /**< The operating system asynchronously destroyed the monitor that corresponds to this handle because the operating system's state changed. This error typically occurs because the monitor PDO associated with this handle was removed or stopped, or a display mode change occurred. A display mode change occurs when Windows sends a WM_DISPLAYCHANGE message to applications. */
#define STATUS_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED                     ((NTSTATUS)0xC01E05E0) /**< This function can be used only if a program is running in the local console session. It cannot be used if a program is running on a remote desktop session or on a terminal server session. */
#define STATUS_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME              ((NTSTATUS)0xC01E05E1) /**< This function cannot find an actual GDI display device that corresponds to the specified GDI display device name. */
#define STATUS_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP             ((NTSTATUS)0xC01E05E2) /**< The function failed because the specified GDI display device was not attached to the Windows desktop. */
#define STATUS_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED                    ((NTSTATUS)0xC01E05E3) /**< This function does not support GDI mirroring display devices because GDI mirroring display devices do not have any physical monitors associated with them. */
#define STATUS_GRAPHICS_INVALID_POINTER                                    ((NTSTATUS)0xC01E05E4) /**< The function failed because an invalid pointer parameter was passed to it. A pointer parameter is invalid if it is null, is not correctly aligned, or points to an invalid address or to a kernel mode address. */
#define STATUS_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE           ((NTSTATUS)0xC01E05E5) /**< This function failed because the GDI device passed to it did not have a monitor associated with it. */
#define STATUS_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL                          ((NTSTATUS)0xC01E05E6) /**< An array passed to the function cannot hold all of the data that the function must copy into the array. */
#define STATUS_GRAPHICS_INTERNAL_ERROR                                     ((NTSTATUS)0xC01E05E7) /**< An internal error caused an operation to fail. */
#define STATUS_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS                    ((NTSTATUS)0xC01E05E8) /**< The function failed because the current session is changing its type. This function cannot be called when the current session is changing its type. Three types of sessions currently exist: console, disconnected, and remote (RDP or ICA). */
#define STATUS_FVE_LOCKED_VOLUME                                           ((NTSTATUS)0xC0210000) /**< The volume must be unlocked before it can be used. */
#define STATUS_FVE_NOT_ENCRYPTED                                           ((NTSTATUS)0xC0210001) /**< The volume is fully decrypted and no key is available. */
#define STATUS_FVE_BAD_INFORMATION                                         ((NTSTATUS)0xC0210002) /**< The control block for the encrypted volume is not valid. */
#define STATUS_FVE_TOO_SMALL                                               ((NTSTATUS)0xC0210003) /**< Not enough free space remains on the volume to allow encryption. */
#define STATUS_FVE_FAILED_WRONG_FS                                         ((NTSTATUS)0xC0210004) /**< The partition cannot be encrypted because the file system is not supported. */
#define STATUS_FVE_FAILED_BAD_FS                                           ((NTSTATUS)0xC0210005) /**< The file system is inconsistent. Run the Check Disk utility. */
#define STATUS_FVE_FS_NOT_EXTENDED                                         ((NTSTATUS)0xC0210006) /**< The file system does not extend to the end of the volume. */
#define STATUS_FVE_FS_MOUNTED                                              ((NTSTATUS)0xC0210007) /**< This operation cannot be performed while a file system is mounted on the volume. */
#define STATUS_FVE_NO_LICENSE                                              ((NTSTATUS)0xC0210008) /**< BitLocker Drive Encryption is not included with this version of Windows. */
#define STATUS_FVE_ACTION_NOT_ALLOWED                                      ((NTSTATUS)0xC0210009) /**< The requested action was denied by the FVE control engine. */
#define STATUS_FVE_BAD_DATA                                                ((NTSTATUS)0xC021000A) /**< The data supplied is malformed. */
#define STATUS_FVE_VOLUME_NOT_BOUND                                        ((NTSTATUS)0xC021000B) /**< The volume is not bound to the system. */
#define STATUS_FVE_NOT_DATA_VOLUME                                         ((NTSTATUS)0xC021000C) /**< The volume specified is not a data volume. */
#define STATUS_FVE_CONV_READ_ERROR                                         ((NTSTATUS)0xC021000D) /**< A read operation failed while converting the volume. */
#define STATUS_FVE_CONV_WRITE_ERROR                                        ((NTSTATUS)0xC021000E) /**< A write operation failed while converting the volume. */
#define STATUS_FVE_OVERLAPPED_UPDATE                                       ((NTSTATUS)0xC021000F) /**< The control block for the encrypted volume was updated by another thread. Try again. */
#define STATUS_FVE_FAILED_SECTOR_SIZE                                      ((NTSTATUS)0xC0210010) /**< The volume encryption algorithm cannot be used on this sector size. */
#define STATUS_FVE_FAILED_AUTHENTICATION                                   ((NTSTATUS)0xC0210011) /**< BitLocker recovery authentication failed. */
#define STATUS_FVE_NOT_OS_VOLUME                                           ((NTSTATUS)0xC0210012) /**< The volume specified is not the boot operating system volume. */
#define STATUS_FVE_KEYFILE_NOT_FOUND                                       ((NTSTATUS)0xC0210013) /**< The BitLocker startup key or recovery password could not be read from external media. */
#define STATUS_FVE_KEYFILE_INVALID                                         ((NTSTATUS)0xC0210014) /**< The BitLocker startup key or recovery password file is corrupt or invalid. */
#define STATUS_FVE_KEYFILE_NO_VMK                                          ((NTSTATUS)0xC0210015) /**< The BitLocker encryption key could not be obtained from the startup key or the recovery password. */
#define STATUS_FVE_TPM_DISABLED                                            ((NTSTATUS)0xC0210016) /**< The TPM is disabled. */
#define STATUS_FVE_TPM_SRK_AUTH_NOT_ZERO                                   ((NTSTATUS)0xC0210017) /**< The authorization data for the SRK of the TPM is not zero. */
#define STATUS_FVE_TPM_INVALID_PCR                                         ((NTSTATUS)0xC0210018) /**< The system boot information changed or the TPM locked out access to BitLocker encryption keys until the computer is restarted. */
#define STATUS_FVE_TPM_NO_VMK                                              ((NTSTATUS)0xC0210019) /**< The BitLocker encryption key could not be obtained from the TPM. */
#define STATUS_FVE_PIN_INVALID                                             ((NTSTATUS)0xC021001A) /**< The BitLocker encryption key could not be obtained from the TPM and PIN. */
#define STATUS_FVE_AUTH_INVALID_APPLICATION                                ((NTSTATUS)0xC021001B) /**< A boot application hash does not match the hash computed when BitLocker was turned on. */
#define STATUS_FVE_AUTH_INVALID_CONFIG                                     ((NTSTATUS)0xC021001C) /**< The Boot Configuration Data (BCD) settings are not supported or have changed because BitLocker was enabled. */
#define STATUS_FVE_DEBUGGER_ENABLED                                        ((NTSTATUS)0xC021001D) /**< Boot debugging is enabled. Run Windows Boot Configuration Data Store Editor (bcdedit.exe) to turn it off. */
#define STATUS_FVE_DRY_RUN_FAILED                                          ((NTSTATUS)0xC021001E) /**< The BitLocker encryption key could not be obtained. */
#define STATUS_FVE_BAD_METADATA_POINTER                                    ((NTSTATUS)0xC021001F) /**< The metadata disk region pointer is incorrect. */
#define STATUS_FVE_OLD_METADATA_COPY                                       ((NTSTATUS)0xC0210020) /**< The backup copy of the metadata is out of date. */
#define STATUS_FVE_REBOOT_REQUIRED                                         ((NTSTATUS)0xC0210021) /**< No action was taken because a system restart is required. */
#define STATUS_FVE_RAW_ACCESS                                              ((NTSTATUS)0xC0210022) /**< No action was taken because BitLocker Drive Encryption is in RAW access mode. */
#define STATUS_FVE_RAW_BLOCKED                                             ((NTSTATUS)0xC0210023) /**< BitLocker Drive Encryption cannot enter RAW access mode for this volume. */
#define STATUS_FVE_NO_FEATURE_LICENSE                                      ((NTSTATUS)0xC0210026) /**< This feature of BitLocker Drive Encryption is not included with this version of Windows. */
#define STATUS_FVE_POLICY_USER_DISABLE_RDV_NOT_ALLOWED                     ((NTSTATUS)0xC0210027) /**< Group policy does not permit turning off BitLocker Drive Encryption on roaming data volumes. */
#define STATUS_FVE_CONV_RECOVERY_FAILED                                    ((NTSTATUS)0xC0210028) /**< Bitlocker Drive Encryption failed to recover from aborted conversion. This could be due to either all conversion logs being corrupted or the media being write-protected. */
#define STATUS_FVE_VIRTUALIZED_SPACE_TOO_BIG                               ((NTSTATUS)0xC0210029) /**< The requested virtualization size is too big. */
#define STATUS_FVE_VOLUME_TOO_SMALL                                        ((NTSTATUS)0xC0210030) /**< The drive is too small to be protected using BitLocker Drive Encryption. */
#define STATUS_FWP_CALLOUT_NOT_FOUND                                       ((NTSTATUS)0xC0220001) /**< The callout does not exist. */
#define STATUS_FWP_CONDITION_NOT_FOUND                                     ((NTSTATUS)0xC0220002) /**< The filter condition does not exist. */
#define STATUS_FWP_FILTER_NOT_FOUND                                        ((NTSTATUS)0xC0220003) /**< The filter does not exist. */
#define STATUS_FWP_LAYER_NOT_FOUND                                         ((NTSTATUS)0xC0220004) /**< The layer does not exist. */
#define STATUS_FWP_PROVIDER_NOT_FOUND                                      ((NTSTATUS)0xC0220005) /**< The provider does not exist. */
#define STATUS_FWP_PROVIDER_CONTEXT_NOT_FOUND                              ((NTSTATUS)0xC0220006) /**< The provider context does not exist. */
#define STATUS_FWP_SUBLAYER_NOT_FOUND                                      ((NTSTATUS)0xC0220007) /**< The sublayer does not exist. */
#define STATUS_FWP_NOT_FOUND                                               ((NTSTATUS)0xC0220008) /**< The object does not exist. */
#define STATUS_FWP_ALREADY_EXISTS                                          ((NTSTATUS)0xC0220009) /**< An object with that GUID or LUID already exists. */
#define STATUS_FWP_IN_USE                                                  ((NTSTATUS)0xC022000A) /**< The object is referenced by other objects and cannot be deleted. */
#define STATUS_FWP_DYNAMIC_SESSION_IN_PROGRESS                             ((NTSTATUS)0xC022000B) /**< The call is not allowed from within a dynamic session. */
#define STATUS_FWP_WRONG_SESSION                                           ((NTSTATUS)0xC022000C) /**< The call was made from the wrong session and cannot be completed. */
#define STATUS_FWP_NO_TXN_IN_PROGRESS                                      ((NTSTATUS)0xC022000D) /**< The call must be made from within an explicit transaction. */
#define STATUS_FWP_TXN_IN_PROGRESS                                         ((NTSTATUS)0xC022000E) /**< The call is not allowed from within an explicit transaction. */
#define STATUS_FWP_TXN_ABORTED                                             ((NTSTATUS)0xC022000F) /**< The explicit transaction has been forcibly canceled. */
#define STATUS_FWP_SESSION_ABORTED                                         ((NTSTATUS)0xC0220010) /**< The session has been canceled. */
#define STATUS_FWP_INCOMPATIBLE_TXN                                        ((NTSTATUS)0xC0220011) /**< The call is not allowed from within a read-only transaction. */
#define STATUS_FWP_TIMEOUT                                                 ((NTSTATUS)0xC0220012) /**< The call timed out while waiting to acquire the transaction lock. */
#define STATUS_FWP_NET_EVENTS_DISABLED                                     ((NTSTATUS)0xC0220013) /**< The collection of network diagnostic events is disabled. */
#define STATUS_FWP_INCOMPATIBLE_LAYER                                      ((NTSTATUS)0xC0220014) /**< The operation is not supported by the specified layer. */
#define STATUS_FWP_KM_CLIENTS_ONLY                                         ((NTSTATUS)0xC0220015) /**< The call is allowed for kernel-mode callers only. */
#define STATUS_FWP_LIFETIME_MISMATCH                                       ((NTSTATUS)0xC0220016) /**< The call tried to associate two objects with incompatible lifetimes. */
#define STATUS_FWP_BUILTIN_OBJECT                                          ((NTSTATUS)0xC0220017) /**< The object is built-in and cannot be deleted. */
#define STATUS_FWP_TOO_MANY_BOOTTIME_FILTERS                               ((NTSTATUS)0xC0220018) /**< The maximum number of boot-time filters has been reached. */
#define STATUS_FWP_TOO_MANY_CALLOUTS                                       ((NTSTATUS)0xC0220018) /**< The maximum number of callouts has been reached. */
#define STATUS_FWP_NOTIFICATION_DROPPED                                    ((NTSTATUS)0xC0220019) /**< A notification could not be delivered because a message queue has reached maximum capacity. */
#define STATUS_FWP_TRAFFIC_MISMATCH                                        ((NTSTATUS)0xC022001A) /**< The traffic parameters do not match those for the security association context. */
#define STATUS_FWP_INCOMPATIBLE_SA_STATE                                   ((NTSTATUS)0xC022001B) /**< The call is not allowed for the current security association state. */
#define STATUS_FWP_NULL_POINTER                                            ((NTSTATUS)0xC022001C) /**< A required pointer is null. */
#define STATUS_FWP_INVALID_ENUMERATOR                                      ((NTSTATUS)0xC022001D) /**< An enumerator is not valid. */
#define STATUS_FWP_INVALID_FLAGS                                           ((NTSTATUS)0xC022001E) /**< The flags field contains an invalid value. */
#define STATUS_FWP_INVALID_NET_MASK                                        ((NTSTATUS)0xC022001F) /**< A network mask is not valid. */
#define STATUS_FWP_INVALID_RANGE                                           ((NTSTATUS)0xC0220020) /**< An FWP_RANGE is not valid. */
#define STATUS_FWP_INVALID_INTERVAL                                        ((NTSTATUS)0xC0220021) /**< The time interval is not valid. */
#define STATUS_FWP_ZERO_LENGTH_ARRAY                                       ((NTSTATUS)0xC0220022) /**< An array that must contain at least one element has a zero length. */
#define STATUS_FWP_NULL_DISPLAY_NAME                                       ((NTSTATUS)0xC0220023) /**< The displayData.name field cannot be null. */
#define STATUS_FWP_INVALID_ACTION_TYPE                                     ((NTSTATUS)0xC0220024) /**< The action type is not one of the allowed action types for a filter. */
#define STATUS_FWP_INVALID_WEIGHT                                          ((NTSTATUS)0xC0220025) /**< The filter weight is not valid. */
#define STATUS_FWP_MATCH_TYPE_MISMATCH                                     ((NTSTATUS)0xC0220026) /**< A filter condition contains a match type that is not compatible with the operands. */
#define STATUS_FWP_TYPE_MISMATCH                                           ((NTSTATUS)0xC0220027) /**< An FWP_VALUE or FWPM_CONDITION_VALUE is of the wrong type. */
#define STATUS_FWP_OUT_OF_BOUNDS                                           ((NTSTATUS)0xC0220028) /**< An integer value is outside the allowed range. */
#define STATUS_FWP_RESERVED                                                ((NTSTATUS)0xC0220029) /**< A reserved field is nonzero. */
#define STATUS_FWP_DUPLICATE_CONDITION                                     ((NTSTATUS)0xC022002A) /**< A filter cannot contain multiple conditions operating on a single field. */
#define STATUS_FWP_DUPLICATE_KEYMOD                                        ((NTSTATUS)0xC022002B) /**< A policy cannot contain the same keying module more than once. */
#define STATUS_FWP_ACTION_INCOMPATIBLE_WITH_LAYER                          ((NTSTATUS)0xC022002C) /**< The action type is not compatible with the layer. */
#define STATUS_FWP_ACTION_INCOMPATIBLE_WITH_SUBLAYER                       ((NTSTATUS)0xC022002D) /**< The action type is not compatible with the sublayer. */
#define STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_LAYER                         ((NTSTATUS)0xC022002E) /**< The raw context or the provider context is not compatible with the layer. */
#define STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_CALLOUT                       ((NTSTATUS)0xC022002F) /**< The raw context or the provider context is not compatible with the callout. */
#define STATUS_FWP_INCOMPATIBLE_AUTH_METHOD                                ((NTSTATUS)0xC0220030) /**< The authentication method is not compatible with the policy type. */
#define STATUS_FWP_INCOMPATIBLE_DH_GROUP                                   ((NTSTATUS)0xC0220031) /**< The Diffie-Hellman group is not compatible with the policy type. */
#define STATUS_FWP_EM_NOT_SUPPORTED                                        ((NTSTATUS)0xC0220032) /**< An IKE policy cannot contain an Extended Mode policy. */
#define STATUS_FWP_NEVER_MATCH                                             ((NTSTATUS)0xC0220033) /**< The enumeration template or subscription will never match any objects. */
#define STATUS_FWP_PROVIDER_CONTEXT_MISMATCH                               ((NTSTATUS)0xC0220034) /**< The provider context is of the wrong type. */
#define STATUS_FWP_INVALID_PARAMETER                                       ((NTSTATUS)0xC0220035) /**< The parameter is incorrect. */
#define STATUS_FWP_TOO_MANY_SUBLAYERS                                      ((NTSTATUS)0xC0220036) /**< The maximum number of sublayers has been reached. */
#define STATUS_FWP_CALLOUT_NOTIFICATION_FAILED                             ((NTSTATUS)0xC0220037) /**< The notification function for a callout returned an error. */
#define STATUS_FWP_INCOMPATIBLE_AUTH_CONFIG                                ((NTSTATUS)0xC0220038) /**< The IPsec authentication configuration is not compatible with the authentication type. */
#define STATUS_FWP_INCOMPATIBLE_CIPHER_CONFIG                              ((NTSTATUS)0xC0220039) /**< The IPsec cipher configuration is not compatible with the cipher type. */
#define STATUS_FWP_DUPLICATE_AUTH_METHOD                                   ((NTSTATUS)0xC022003C) /**< A policy cannot contain the same auth method more than once. */
#define STATUS_FWP_TCPIP_NOT_READY                                         ((NTSTATUS)0xC0220100) /**< The TCP/IP stack is not ready. */
#define STATUS_FWP_INJECT_HANDLE_CLOSING                                   ((NTSTATUS)0xC0220101) /**< The injection handle is being closed by another thread. */
#define STATUS_FWP_INJECT_HANDLE_STALE                                     ((NTSTATUS)0xC0220102) /**< The injection handle is stale. */
#define STATUS_FWP_CANNOT_PEND                                             ((NTSTATUS)0xC0220103) /**< The classify cannot be pended. */
#define STATUS_NDIS_CLOSING                                                ((NTSTATUS)0xC0230002) /**< The binding to the network interface is being closed. */
#define STATUS_NDIS_BAD_VERSION                                            ((NTSTATUS)0xC0230004) /**< An invalid version was specified. */
#define STATUS_NDIS_BAD_CHARACTERISTICS                                    ((NTSTATUS)0xC0230005) /**< An invalid characteristics table was used. */
#define STATUS_NDIS_ADAPTER_NOT_FOUND                                      ((NTSTATUS)0xC0230006) /**< Failed to find the network interface or the network interface is not ready. */
#define STATUS_NDIS_OPEN_FAILED                                            ((NTSTATUS)0xC0230007) /**< Failed to open the network interface. */
#define STATUS_NDIS_DEVICE_FAILED                                          ((NTSTATUS)0xC0230008) /**< The network interface has encountered an internal unrecoverable failure. */
#define STATUS_NDIS_MULTICAST_FULL                                         ((NTSTATUS)0xC0230009) /**< The multicast list on the network interface is full. */
#define STATUS_NDIS_MULTICAST_EXISTS                                       ((NTSTATUS)0xC023000A) /**< An attempt was made to add a duplicate multicast address to the list. */
#define STATUS_NDIS_MULTICAST_NOT_FOUND                                    ((NTSTATUS)0xC023000B) /**< At attempt was made to remove a multicast address that was never added. */
#define STATUS_NDIS_REQUEST_ABORTED                                        ((NTSTATUS)0xC023000C) /**< The network interface aborted the request. */
#define STATUS_NDIS_RESET_IN_PROGRESS                                      ((NTSTATUS)0xC023000D) /**< The network interface cannot process the request because it is being reset. */
#define STATUS_NDIS_INVALID_PACKET                                         ((NTSTATUS)0xC023000F) /**< An attempt was made to send an invalid packet on a network interface. */
#define STATUS_NDIS_INVALID_DEVICE_REQUEST                                 ((NTSTATUS)0xC0230010) /**< The specified request is not a valid operation for the target device. */
#define STATUS_NDIS_ADAPTER_NOT_READY                                      ((NTSTATUS)0xC0230011) /**< The network interface is not ready to complete this operation. */
#define STATUS_NDIS_INVALID_LENGTH                                         ((NTSTATUS)0xC0230014) /**< The length of the buffer submitted for this operation is not valid. */
#define STATUS_NDIS_INVALID_DATA                                           ((NTSTATUS)0xC0230015) /**< The data used for this operation is not valid. */
#define STATUS_NDIS_BUFFER_TOO_SHORT                                       ((NTSTATUS)0xC0230016) /**< The length of the submitted buffer for this operation is too small. */
#define STATUS_NDIS_INVALID_OID                                            ((NTSTATUS)0xC0230017) /**< The network interface does not support this object identifier. */
#define STATUS_NDIS_ADAPTER_REMOVED                                        ((NTSTATUS)0xC0230018) /**< The network interface has been removed. */
#define STATUS_NDIS_UNSUPPORTED_MEDIA                                      ((NTSTATUS)0xC0230019) /**< The network interface does not support this media type. */
#define STATUS_NDIS_GROUP_ADDRESS_IN_USE                                   ((NTSTATUS)0xC023001A) /**< An attempt was made to remove a token ring group address that is in use by other components. */
#define STATUS_NDIS_FILE_NOT_FOUND                                         ((NTSTATUS)0xC023001B) /**< An attempt was made to map a file that cannot be found. */
#define STATUS_NDIS_ERROR_READING_FILE                                     ((NTSTATUS)0xC023001C) /**< An error occurred while NDIS tried to map the file. */
#define STATUS_NDIS_ALREADY_MAPPED                                         ((NTSTATUS)0xC023001D) /**< An attempt was made to map a file that is already mapped. */
#define STATUS_NDIS_RESOURCE_CONFLICT                                      ((NTSTATUS)0xC023001E) /**< An attempt to allocate a hardware resource failed because the resource is used by another component. */
#define STATUS_NDIS_MEDIA_DISCONNECTED                                     ((NTSTATUS)0xC023001F) /**< The I/O operation failed because the network media is disconnected or the wireless access point is out of range. */
#define STATUS_NDIS_INVALID_ADDRESS                                        ((NTSTATUS)0xC0230022) /**< The network address used in the request is invalid. */
#define STATUS_NDIS_PAUSED                                                 ((NTSTATUS)0xC023002A) /**< The offload operation on the network interface has been paused. */
#define STATUS_NDIS_INTERFACE_NOT_FOUND                                    ((NTSTATUS)0xC023002B) /**< The network interface was not found. */
#define STATUS_NDIS_UNSUPPORTED_REVISION                                   ((NTSTATUS)0xC023002C) /**< The revision number specified in the structure is not supported. */
#define STATUS_NDIS_INVALID_PORT                                           ((NTSTATUS)0xC023002D) /**< The specified port does not exist on this network interface. */
#define STATUS_NDIS_INVALID_PORT_STATE                                     ((NTSTATUS)0xC023002E) /**< The current state of the specified port on this network interface does not support the requested operation. */
#define STATUS_NDIS_LOW_POWER_STATE                                        ((NTSTATUS)0xC023002F) /**< The miniport adapter is in a lower power state. */
#define STATUS_NDIS_NOT_SUPPORTED                                          ((NTSTATUS)0xC02300BB) /**< The network interface does not support this request. */
#define STATUS_NDIS_OFFLOAD_POLICY                                         ((NTSTATUS)0xC023100F) /**< The TCP connection is not offloadable because of a local policy setting. */
#define STATUS_NDIS_OFFLOAD_CONNECTION_REJECTED                            ((NTSTATUS)0xC0231012) /**< The TCP connection is not offloadable by the Chimney offload target. */
#define STATUS_NDIS_OFFLOAD_PATH_REJECTED                                  ((NTSTATUS)0xC0231013) /**< The IP Path object is not in an offloadable state. */
#define STATUS_NDIS_DOT11_AUTO_CONFIG_ENABLED                              ((NTSTATUS)0xC0232000) /**< The wireless LAN interface is in auto-configuration mode and does not support the requested parameter change operation. */
#define STATUS_NDIS_DOT11_MEDIA_IN_USE                                     ((NTSTATUS)0xC0232001) /**< The wireless LAN interface is busy and cannot perform the requested operation. */
#define STATUS_NDIS_DOT11_POWER_STATE_INVALID                              ((NTSTATUS)0xC0232002) /**< The wireless LAN interface is power down and does not support the requested operation. */
#define STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL                               ((NTSTATUS)0xC0232003) /**< The list of wake on LAN patterns is full. */
#define STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL                          ((NTSTATUS)0xC0232004) /**< The list of low power protocol offloads is full. */
#define STATUS_IPSEC_BAD_SPI                                               ((NTSTATUS)0xC0360001) /**< The SPI in the packet does not match a valid IPsec SA. */
#define STATUS_IPSEC_SA_LIFETIME_EXPIRED                                   ((NTSTATUS)0xC0360002) /**< The packet was received on an IPsec SA whose lifetime has expired. */
#define STATUS_IPSEC_WRONG_SA                                              ((NTSTATUS)0xC0360003) /**< The packet was received on an IPsec SA that does not match the packet characteristics. */
#define STATUS_IPSEC_REPLAY_CHECK_FAILED                                   ((NTSTATUS)0xC0360004) /**< The packet sequence number replay check failed. */
#define STATUS_IPSEC_INVALID_PACKET                                        ((NTSTATUS)0xC0360005) /**< The IPsec header and/or trailer in the packet is invalid. */
#define STATUS_IPSEC_INTEGRITY_CHECK_FAILED                                ((NTSTATUS)0xC0360006) /**< The IPsec integrity check failed. */
#define STATUS_IPSEC_CLEAR_TEXT_DROP                                       ((NTSTATUS)0xC0360007) /**< IPsec dropped a clear text packet. */
#define STATUS_IPSEC_AUTH_FIREWALL_DROP                                    ((NTSTATUS)0xC0360008) /**< IPsec dropped an incoming ESP packet in authenticated firewall mode.  This drop is benign. */
#define STATUS_IPSEC_THROTTLE_DROP                                         ((NTSTATUS)0xC0360009) /**< IPsec dropped a packet due to DOS throttle. */
#define STATUS_IPSEC_DOSP_BLOCK                                            ((NTSTATUS)0xC0368000) /**< IPsec Dos Protection matched an explicit block rule. */
#define STATUS_IPSEC_DOSP_RECEIVED_MULTICAST                               ((NTSTATUS)0xC0368001) /**< IPsec Dos Protection received an IPsec specific multicast packet which is not allowed. */
#define STATUS_IPSEC_DOSP_INVALID_PACKET                                   ((NTSTATUS)0xC0368002) /**< IPsec Dos Protection received an incorrectly formatted packet. */
#define STATUS_IPSEC_DOSP_STATE_LOOKUP_FAILED                              ((NTSTATUS)0xC0368003) /**< IPsec Dos Protection failed to lookup state. */
#define STATUS_IPSEC_DOSP_MAX_ENTRIES                                      ((NTSTATUS)0xC0368004) /**< IPsec Dos Protection failed to create state because there are already maximum number of entries allowed by policy. */
#define STATUS_IPSEC_DOSP_KEYMOD_NOT_ALLOWED                               ((NTSTATUS)0xC0368005) /**< IPsec Dos Protection received an IPsec negotiation packet for a keying module which is not allowed by policy. */
#define STATUS_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES                      ((NTSTATUS)0xC0368006) /**< IPsec Dos Protection failed to create per internal IP ratelimit queue because there is already maximum number of queues allowed by policy. */
#define STATUS_VOLMGR_MIRROR_NOT_SUPPORTED                                 ((NTSTATUS)0xC038005B) /**< The system does not support mirrored volumes. */
#define STATUS_VOLMGR_RAID5_NOT_SUPPORTED                                  ((NTSTATUS)0xC038005C) /**< The system does not support RAID-5 volumes. */
#define STATUS_VIRTDISK_PROVIDER_NOT_FOUND                                 ((NTSTATUS)0xC03A0014) /**< A virtual disk support provider for the specified file was not found. */
#define STATUS_VIRTDISK_NOT_VIRTUAL_DISK                                   ((NTSTATUS)0xC03A0015) /**< The specified disk is not a virtual disk. */
#define STATUS_VHD_PARENT_VHD_ACCESS_DENIED                                ((NTSTATUS)0xC03A0016) /**< The chain of virtual hard disks is inaccessible. The process has not been granted access rights to the parent virtual hard disk for the differencing disk. */
#define STATUS_VHD_CHILD_PARENT_SIZE_MISMATCH                              ((NTSTATUS)0xC03A0017) /**< The chain of virtual hard disks is corrupted. There is a mismatch in the virtual sizes of the parent virtual hard disk and differencing disk. */
#define STATUS_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED                       ((NTSTATUS)0xC03A0018) /**< The chain of virtual hard disks is corrupted. A differencing disk is indicated in its own parent chain. */
#define STATUS_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT                      ((NTSTATUS)0xC03A0019) /**< The chain of virtual hard disks is inaccessible. There was an error opening a virtual hard disk further up the chain. */
#define STATUS_SMB_NO_PREAUTH_INTEGRITY_HASH_OVERLAP                       ((NTSTATUS)0xC05D0000) /**< Returned in response to a client negotiate request when the server does not support any of the hash algorithms in the request. */
#define STATUS_SMB_BAD_CLUSTER_DIALECT                                     ((NTSTATUS)0xC05D0001) /**< The current cluster functional level does not support this SMB dialect. Last updated on 11/16/2021 AI Disclaimer Previous Versions Blog Contribute Privacy Consumer Health Privacy Terms of Use Trademarks © Microsoft 2026 */

#endif /* NTSTATUS_CODES_H */
